package Color

class Color(var r: Double = 0, var g: Double = 0, var b: Double = 0)
{
    override def toString(): String = s"($r, $g, $b)"
    def toInt() = new java.awt.Color((r * 255).toInt, (g * 255).toInt, (b * 255).toInt).getRGB()
}
