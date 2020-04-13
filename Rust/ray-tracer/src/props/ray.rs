extern crate cgmath;

use cgmath::Vector3;

use crate::rendering::objects::Scene;

// pub struct ImagePlane {
// }

pub struct Ray {
    pub origin:    Vector3<f64>,
    pub direction: Vector3<f64>
}

impl Ray {

    pub fn new(x: f64, y: f64, z: f64) -> Ray {
        Ray {
            origin:    Vector3::new(x, y, z),
            direction: Vector3 { x: 0.0, y: 0.0, z: 0.0 }
        }
    }

    pub fn zero() -> Ray {
        Ray {
            origin:    Vector3 { x: 0.0, y: 0.0, z: 0.0 },
            direction: Vector3 { x: 0.0, y: 0.0, z: 0.0 }
        }
    }

    /// The image plane will look like this:
    ///
    ///    1
    /// -1 *---*---* 1
    ///    |   |   |
    ///    *---*---*
    ///    |   |   |
    ///    *---*---*
    ///   -1
    ///
    /// We need to transform pixels into the scene's coordinates, that's why we use an "image plane".
    pub fn create_prime(x: f64, y: f64, scene: &Scene) -> Ray {

        // We add .5 to put the ray in the center of a pixel, not at it's (0, 0) coordinates.
        // Mul by 2 and sub by 1 transforms the result in the [-1; 1] bounds.
        let image_plane_x = ((x * 0.5) / scene.width  as f64) * 2.0 - 1.0;
        let image_plane_y = ((y * 0.5) / scene.height as f64) * 2.0 - 1.0;

        Ray {
            origin:    Vector3::new(0.0, 0.0, 0.0),
            direction: Vector3::new(image_plane_x, image_plane_y, -1.0)
        }
    }
}
