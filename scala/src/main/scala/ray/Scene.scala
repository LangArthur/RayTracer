package Scene

import Color._
import Vec3._

object ColorEnum
{
    val WHITE: Color = new Color(1, 1, 1)
    val GREENISH: Color = new Color(0.5, 1, 0.5)
    val GRAY: Color = new Color(0.5, 0.5, 0.5)
    val BLACK: Color = new Color(0, 0, 0)
}

case class Light(var pos: Vec3 = new Vec3(0, 0, 0), var color: Color = new Color(1, 1, 1))

case class Ray(var origin: Vec3 = new Vec3(), var direction: Vec3 = new Vec3(1, 0, 0))

class Camera(var pos: Vec3 = new Vec3())
