package Camera

import Vec3._

class Camera(
    var pos: Vec3 = new Vec3(),
    var dir: Vec3 = new Vec3(0, 0, 1),
    var right: Vec3 = new Vec3(),
    var down: Vec3 = new Vec3()
)
{
}
