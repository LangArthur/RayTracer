use crate::props::ray::Ray;

pub trait Intersect {
    fn hit(&self, ray: &Ray) -> bool;
}
