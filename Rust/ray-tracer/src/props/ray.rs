extern crate num;

use num::Num;

use crate::props::point::Point;
use crate::props::vector::Vector3;

pub struct Ray<T>
where T: Num + PartialOrd + Copy {
    pub origin:    Point<T>,
    pub direction: Vector3<T>
}

impl<T> Ray<T>
where T: Num + PartialOrd + Copy {

    pub fn new(x: T, y: T, z: T) -> Ray<T> {
        Ray {
            origin: Point { x, y, z },
            direction: Vector3::zero()
        }
    }

    pub fn zero() -> Ray<T> {
        Ray {
            origin: Point::zero(),
            direction: Vector3::zero()
        }
    }
}
