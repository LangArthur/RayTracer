extern crate cgmath;

use cgmath::Vector3;
use crate::props::ray::Ray;
use crate::props::color::Color;
use crate::props::albedo::Albedo;

pub trait Drawable {

    fn hit(&self, ray: &Ray) -> Option<f64>;
    fn surface_normal(&self, hit: Vector3<f64>) -> Vector3<f64>;

    // To optimise with lifetimes.
    fn color(&self) -> &Color;
    fn albedo(&self) -> &Albedo;
}

pub trait Light {

    fn direction(&self) -> &Vector3<f64>;
    fn intensity(&self) -> f64;
    fn color(&self) -> &Color;
}