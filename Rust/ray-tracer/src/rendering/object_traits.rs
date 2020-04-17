use crate::props::ray::Ray;
use crate::props::color::Color;
use crate::props::albedo::Albedo;

pub trait Drawable {

    fn hit(&self, ray: &Ray) -> Option<f64>;

    // To optimise with lifetimes.
    fn color(&self) -> &Color;
    fn albedo(&self) -> &Albedo;
}
