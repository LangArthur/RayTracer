extern crate cgmath;

use cgmath::Vector3;
use crate::props::color::Color;

pub struct Light {

    pub origin:    Vector3<f64>,
    pub direction: Vector3<f64>,
    pub color:     Color,
    pub intensity: f64
}