package Vec3

class Vec3(var x: Double = 0, var y: Double = 0, var z: Double = 0)
{
    override def toString(): String = s"($x, $y, $z)"

    def +(vec: Vec3): Vec3 = new Vec3(x + vec.x, y + vec.y, z + vec.z)
    def -(vec: Vec3): Vec3 = new Vec3(x - vec.x, y - vec.y, z - vec.z)
    def *(nb: Double): Vec3 = new Vec3(x * nb, y * nb, z * nb)
    def /(nb: Double): Vec3 = new Vec3(x / nb, y / nb, z / nb)

    def len(): Double = Math.sqrt(x * x + y * y + z * z)
    def lenSqr(): Double = x * x + y * y + z * z
    def normalize(): Vec3 = this / len()
    def dot(vec: Vec3): Double = x * vec.x + y * vec.y + z * vec.z
    def negate(): Vec3 = new Vec3(-x, -y, -z)
    def cross(vec: Vec3): Vec3 = new Vec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x)
    //def lerp()
}
/*
class Matrix3(var arr: Array[Double])
{
    override def toString(): String =
        "[[" + arr(0) + ", " + arr(1) + ", " + arr(2) + "],\n" +
        " [" + arr(3) + ", " + arr(4) + ", " + arr(5) + "],\n" +
        " [" + arr(6) + ", " + arr(7) + ", " + arr(8) + "]]"
}
*/