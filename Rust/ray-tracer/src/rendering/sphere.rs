extern crate cgmath;

use cgmath::Point3;
use crate::props::color::Color;

/// A sphere struct that contains data to render a sphere in a scene.
pub struct Sphere {
    pub center: Point3<f64>,
    pub radius: f64,
    pub color:  Color
}
