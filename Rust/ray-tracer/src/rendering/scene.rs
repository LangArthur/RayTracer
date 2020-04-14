use std::vec::Vec;
use crate::rendering::object_traits::Drawable;

/// A struct that will hold objects to be rendered.
pub struct Scene {
    pub width:   u32,
    pub height:  u32,
    pub fov:     f64,
    pub objects: Vec<Box<dyn Drawable>>
}
