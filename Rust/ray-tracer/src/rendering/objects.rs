use crate::props;

/// A sphere struct that contains data to render a sphere in a scene.
pub struct Sphere {
    pub center: props::point::Point,
    pub radius: f64,
    pub color:  props::color::Color
}

/// A struct that will hold objects to be rendered.
pub struct Scene {
    pub width:  u32,
    pub height: u32,
    pub fov:    f64,
    pub sphere: Sphere
}