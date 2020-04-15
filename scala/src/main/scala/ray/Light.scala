package Light

import Vec3._
import Color._

object ColorEnum
{
    val WHITE: Color = new Color(1, 1, 1)
    val GREENISH: Color = new Color(0.5, 1, 0.5)
    val GRAY: Color = new Color(0.5, 0.5, 0.5)
    val BLACK: Color = new Color(0, 0, 0)
}

class Light(var pos: Vec3 = new Vec3(0, 0, 0), var color: Color = new Color(1, 1, 1))
{

}
