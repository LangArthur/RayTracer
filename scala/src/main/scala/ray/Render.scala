package Render

import Array._
import Vec3._
import Camera._
import Light._
import Sphere._
import Plane._
import Ray._
import Object._
import Color.Color

object Render
{
    val HEIGHT: Int = 480
    val WIDTH: Int = 640
    val ASPECT_RATIO: Double = (WIDTH.toDouble/HEIGHT.toDouble).toInt
    val O: Vec3 = new Vec3(0, 0, 0)
    val X: Vec3 = new Vec3(1, 0, 0)
    val Y: Vec3 = new Vec3(0, 1, 0)
    val Z: Vec3 = new Vec3(0, 0, 1)

    def render(): Array[Color] = {
        val camPos: Vec3 = new Vec3(3, 1.5, -4)
        val lookAt: Vec3 = new Vec3(0, 0, 0)
        val diff: Vec3 = camPos - lookAt
        val camDir: Vec3 = diff.negate().normalize()
        val camRight: Vec3 = Y.cross(camDir).normalize()
        val camDown: Vec3 = camRight.cross(camDir)

        val camera: Camera = new Camera(camPos, camDir, camRight, camDown)
        val light: Light = new Light(new Vec3(-7, 10, -10), ColorEnum.WHITE)

        var xamnt: Double = 0
        var yamnt: Double = 0

        // Scene objects
        val sceneObjects: Array[Object] = new Array[Object](1)
        //sceneObjects(0) = new Sphere(O, 1, ColorEnum.GREENISH)
        sceneObjects(0) = new Plane(Y, new Vec3(0, -1, 0), ColorEnum.GRAY)

        var framebuffer = new Array[Color](WIDTH * HEIGHT)
        for (y <- 0 until HEIGHT)
            for (x <- 0 until WIDTH) {
                xamnt = ((x + 0.5) / WIDTH) * ASPECT_RATIO - (((WIDTH - HEIGHT) / HEIGHT.toDouble) / 2)
                yamnt = ((HEIGHT - y) + 0.5) / HEIGHT

                val camDirRay: Vec3 = (camDir + (camRight * (xamnt - 0.5) + camDown * (yamnt - 0.5))).normalize()
                val camRay: Ray = new Ray(camera.pos, camDirRay)

                var intersections: Array[Double] = new Array[Double](sceneObjects.size)
                for (i <- 0 until sceneObjects.size)
                    intersections(i) = sceneObjects(i).intersect(camRay)

                val closestObject: Int = getClosestObj(intersections)

//                framebuffer(x*y+x) = new Color(1, 1, 1)

                if (closestObject == -1)
                    framebuffer(WIDTH*y+x) = new Color(0, 0, 0)
                else
                    framebuffer(WIDTH*y+x) = sceneObjects(closestObject).color
            }
        framebuffer
    }

    def getClosestObj(inter: Array[Double]): Int = {
        if (inter.size == 0)
            -1
        else if (inter.size == 1) {
            if (inter(0) > 0)
                0
            -1
        } else {
            val other: Array[Double] = inter.filter(_ > 0)
            if (other.size == 0)
                -1
            else
                inter.indexOf[Double](other.min[Double])
        }
    }
}
