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
    /// passed as parameter and the camera using the pythagorian formula.
    fn hit(&self, ray: &Ray) -> Option<f64> {

        // Square radius of the sphere, we'll need it later to speed up calculations.
        let rad_sqrt = self.radius * self.radius;

        // Calculating the distance between the camera and the origin of the sphere.
        let hypotenuse: Vector3<f64> = self.center - ray.origin;

        // Calculating the distance between the camera and a line starting from
        // the origin of the sphere using the scalar product of both vectors.
        let from_cam = hypotenuse.dot(ray.direction);

        // Calculating the length of the line that crosses the hypotenuse starting from
        // the center of the sphere. -> pythagore.
        // CB² = AB² + AC² -> AC² = CB² (hypotenuse) - AB² (len_to_center).
        let inter_dist_sqrt = hypotenuse.dot(hypotenuse) - from_cam * from_cam;

        // Checking if the ray hit the sphere.
        // if AC is smaller than the raised by two radius of the sphere, then the ray has hit the sphere.
        if inter_dist_sqrt > rad_sqrt {
            return None;
        }

        // let's now calculate the distance between the point at the opposite of the 90° angle
        // and the intersection of the ray. The radius will act as the hypotenuse.
        Some(from_cam - (rad_sqrt - inter_dist_sqrt).sqrt())
    }

    fn color(&self) -> &Color {
        &self.color
    }
}
