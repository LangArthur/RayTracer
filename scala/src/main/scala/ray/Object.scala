package Object

import Color._
import Scene._
import Vec3._

trait Object
{
    def color: Color
    def intersect(ray: Ray): Double
}

case class Sphere(
    var center: Vec3 = new Vec3(0, 0, 0),
    var radius: Double = 1,
    var color: Color = new Color(0.5, 0.5, 0.5)
) extends Object
{
    def getNormalAt(point: Vec3): Vec3 = new Vec3()

    def intersect(ray: Ray): Double = {
        1.0
    }
}
