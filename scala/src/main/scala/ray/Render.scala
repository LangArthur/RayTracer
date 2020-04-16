package Render

import Array._
import Vec3._
import Scene._
import Object._
import Color._

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
        val s: Sphere = Sphere()

        var framebuffer = new Array[Color](WIDTH * HEIGHT)
        for (y <- 0 until HEIGHT)
            for (x <- 0 until WIDTH) {
                framebuffer(WIDTH*y+x) = new Color(1, 1, 1)
            }
        framebuffer
    }
}
