package Object

import Color._
import Ray._

trait Object
{
    def color: Color
    def intersect(ray: Ray): Double
}
