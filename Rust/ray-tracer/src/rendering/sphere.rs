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

    /// A function that calculates the distance between a point hit by the ray
    /// passed as parameter and the camera using Al-Kashi's algorithm.
    fn hit(&self, ray: &Ray) -> Option<f64> {

        // Square radius of the sphere, we'll need it later to speed up calculations.
        let square_radius = self.radius.powf(2.0);

        // Calculating the distance between the camera and the origin of the sphere.
        let hypotenuse: Vector3<f64> = ray.origin - self.center;

        // Calculating the distance between the camera and a line starting from
        // the origin of the sphere using the scalar product of both vectors.
        let len_to_angle = hypotenuse.dot(ray.direction);

        // Calculating the length of the line that crosses the hypotenuse starting from
        // the center of the sphere. -> pythagore.
        // CB² = AB² + AC² -> AC² = CB² (hypotenuse) - AB² (len_to_center).
        let intersect_distance = hypotenuse.dot(hypotenuse) - len_to_angle.powf(2.0);

        // Checking if the ray hit the sphere.
        // if AC is smaller than the raised by two radius of the sphere, then the ray has hit the sphere.
        if intersect_distance > square_radius {
            return None;
        }

        // Let's now calculate the distance between the point at the opposite of the 90° angle
        // and the intersection of the ray. The radius will act as the hypotenuse.
        Some(len_to_angle - (square_radius - intersect_distance).sqrt())
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
