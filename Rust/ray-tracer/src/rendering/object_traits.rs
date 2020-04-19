extern crate cgmath;

use cgmath::Vector3;
use crate::props::ray::Ray;
use crate::props::color::Color;
use crate::props::material::Material;

pub trait Drawable {

    fn hit(&self, ray: &Ray) -> Option<f64>;
    fn surface_normal(&self, hit: Vector3<f64>) -> Vector3<f64>;

    fn material_data(&self) -> &Material;
}

pub trait Light {

    fn direction_from(&self, hit :Vector3<f64>) -> Vector3<f64>;
    fn intensity(&self, hit :Vector3<f64>) -> f64;
    fn distance(&self, hit :Vector3<f64>) -> f64;
    fn color(&self) -> &Color;
}