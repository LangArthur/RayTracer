extern crate cgmath;

use cgmath::Vector3;
use cgmath::InnerSpace;
use crate::props::ray::Ray;
use crate::props::color::Color;
use crate::rendering::object_traits::Drawable;

/// A sphere struct that contains data to render a sphere in a scene.
pub struct Sphere {
    pub center: Vector3<f64>,
    pub radius: f64,
    pub color:  Color
}

impl Drawable for Sphere {
    fn hit(&self, ray: &Ray) -> Option<f64> {

        // A *-----* B
        //   |  --
        // C *--

        // len_to_center      = AB
        // hypotenuse         = CB
        // intersect_distance = AC -> That's what we need to find.

        // Calculating the distance between the camera and the origin of the sphere.
        let len_to_center: Vector3<f64> = ray.origin - self.center;

        // Calculating the distance between the camera and a line starting from
        // the origin of the sphere using the scalar product of both vectors.
        let hypotenuse = len_to_center.dot(ray.direction);

        // Calculating the length of the line that crosses the hypotenuse starting from
        // the center of the sphere. -> pythagore.
        // CB² = AB² + AC² -> AC² = CB² (hypotenuse) - AB² (len_to_center).
        let intersect_distance = len_to_center.dot(len_to_center) - hypotenuse * hypotenuse;

        // if AC is smaller than the radius of the sphere, then the ray has hit the sphere.
        if intersect_distance < (self.radius * self.radius) {
            return Some(intersect_distance);
        }
        None
    }

    fn color(&self) -> Color {
        Color {
            r: self.color.r,
            g: self.color.g,
            b: self.color.b,
            a: self.color.a,
        }
    }
}
