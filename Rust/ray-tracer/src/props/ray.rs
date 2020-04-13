extern crate num;

use num::Num;

use crate::props::vector::Vector3;

// pub struct ImagePlane {
    
// }

pub struct Ray<T>
where T: Num + PartialOrd + Copy {
    pub origin:    Vector3<T>,
    pub direction: Vector3<T>
}

impl<T> Ray<T>
where T: Num + PartialOrd + Copy {

    pub fn new(x: T, y: T, z: T) -> Ray<T> {
        Ray {
            origin:    Vector3::new(x, y, z),
            direction: Vector3::zero()
        }
    }

    pub fn zero() -> Ray<T> {
        Ray {
            origin:    Vector3::zero(),
            direction: Vector3::zero()
        }
    }
}
