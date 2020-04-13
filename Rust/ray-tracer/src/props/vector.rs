extern crate num;

use num::Num;

use std::ops::Add;
use std::ops::Sub;
use std::ops::Mul;

/// Vector class with three dimensions.
#[derive(Debug)]
pub struct Vector3<T: Num + PartialOrd + Copy> {
    pub x: T,
    pub y: T,
    pub z: T
}

impl<T: Num + PartialOrd + Copy> Vector3<T> {
    pub fn new(x: T, y: T, z: T) -> Vector3<T> {
        Vector3 {
            x,
            y,
            z
        }
    }

    pub fn zero() -> Vector3<T> {
        Vector3 {
            x: T::zero(),
            y: T::zero(),
            z: T::zero()
        }
    }
}

impl<T> Add for Vector3<T>
where T: Num + PartialOrd + Copy + Add<Output = T> {

    type Output = Self;

    fn add(self, other: Self) -> Self::Output {
        Self {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z
        }
    }
}

impl<T> Sub for Vector3<T>
where T: Num + PartialOrd + Copy + Sub<Output = T> {

    type Output = Self;

    fn sub(self, other: Self) -> Self::Output {
        Self {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z
        }
    }
}

impl<T> Mul for Vector3<T>
where T: Num + PartialOrd + Copy + Mul<Output = T> {

    type Output = Self;

    fn mul(self, other: Self) -> Self::Output {
        Self {
            x: self.x * other.x,
            y: self.y * other.y,
            z: self.z * other.z
        }
    }
}
