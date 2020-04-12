/// A structure that holds coordinates.
pub struct Point {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}

/// A color struct containing rgba values.
pub struct Color {
    pub r: u8,
    pub g: u8,
    pub b: u8,
    pub a: u8
}

/// A sphere struct that contains data to render a sphere in a scene.
pub struct Sphere {
    pub center: Point,
    pub radius: f64,
    pub color:  Color
}

/// A struct that will hold objects to be rendered.
pub struct Scene {
    pub width:  u32,
    pub height: u32,
    pub fov:    f64,
    pub sphere: Sphere
}
