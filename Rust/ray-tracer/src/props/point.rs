extern crate num;

use num::Num;

/// A structure that holds coordinates.
pub struct Point<T: Num + PartialOrd + Copy> {
    pub x: T,
    pub y: T,
    pub z: T
}

impl<T: Num + PartialOrd + Copy> Point<T> {
    pub fn new(x: T, y: T, z: T) -> Point<T> {
        Point {
            x,
            y,
            z
        }
    }

    pub fn zero() -> Point<T> {
        Point {
            x: T::zero(),
            y: T::zero(),
            z: T::zero()
        }
    }
}
