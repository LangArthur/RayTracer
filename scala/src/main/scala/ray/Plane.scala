package Plane

import Object._
import Ray._
import Vec3._
import Color._

class Plane(
    var normal: Vec3 = new Vec3(1, 0, 0),
    var pos: Vec3 = new Vec3(0, 0, 0),
    var color: Color = new Color(0.5, 0.5, 0.5)
) extends Object
{
    def getNormalAt(point: Vec3): Vec3 = normal

    def intersect(ray: Ray): Double = {
        val denom: Double = ray.direction.dot(normal)

        if (Math.abs(denom) < 0.00001)
            -1
        (pos - ray.origin).dot(normal) / denom
    }
}
