extern crate cgmath;
use cgmath::Vector3;

use crate::props::color::Color;
use crate::rendering::object_traits::Light;

pub struct DirectionalLight {

    pub direction: Vector3<f64>,
    pub color:     Color,
    pub intensity: f64
}

impl Light for DirectionalLight {

    fn direction(&self) -> &Vector3<f64> {
        &self.direction
    }
    fn intensity(&self) -> f64 {
        self.intensity
    }

    fn color(&self) -> &Color {
        &self.color
    }
}

pub struct SphericalLight {

    pub origin:    Vector3<f64>,
    pub color:     Color,
    pub intensity: f64
}

impl Light for SphericalLight {
    
    fn direction(&self) -> &Vector3<f64> {
        &self.origin
    }
    fn intensity(&self) -> f64 {
        self.intensity
    }

    fn color(&self) -> &Color {
        &self.color
    }
}