package Sphere

import Vec3._
import Color._
import Object._
import Ray._

class Sphere(
    var center: Vec3 = new Vec3(0, 0, 0),
    var radius: Double = 1,
    var color: Color = new Color(0.5, 0.5, 0.5)
) extends Object
{
    def getNormalAt(point: Vec3): Vec3 = (point + center.negate()).normalize()

    def intersect(ray: Ray): Double = {
        val a: Double = 1
        val b: Double = (2 * (ray.origin.x - center.x) * ray.direction.x)
            + (2 * (ray.origin.y - center.y) * ray.direction.y)
            + (2 * (ray.origin.z - center.z) * ray.direction.z)
        val c: Double = Math.pow(ray.origin.x - center.x, 2)
            + Math.pow(ray.origin.y - center.y, 2)
            + Math.pow(ray.origin.z - center.z, 2)
            - (radius * radius)
        val disc = b * b - 4 * c

        if (disc < 0) {
            -1
        } else if (disc > 0) {
            val r1: Double = ((-b - Math.sqrt(disc)) / 2) - 0.00001
            if (r1 > 0)
                r1
            ((-b + Math.sqrt(disc)) / 2) - 0.00001
        }
        (-b / 2) - 0.00001
    }
}
