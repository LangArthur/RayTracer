extern crate cgmath;
use cgmath::Vector2;

use crate::props::color::Color;

pub struct Texture {
    pub coords:  Vector2<f64>,
    pub texture: f64
}

pub struct Material {

    pub texture: Option<Texture>,
    pub albedo:  f64,
    pub color:   Color
}