use crate::rendering::prop;

/// A sphere struct that contains data to render a sphere in a scene.
pub struct Sphere {
    pub center: prop::Point,
    pub radius: f64,
    pub color:  prop::Color
}

/// A struct that will hold objects to be rendered.
pub struct Scene {
    pub width:  u32,
    pub height: u32,
    pub fov:    f64,
    pub sphere: Sphere
}
