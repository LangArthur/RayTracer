use std::ops::Add;
use std::ops::Sub;
use std::ops::Mul;

/// Vector class with three dimensions.
#[derive(Debug)]
pub struct Vector3<T: PartialOrd + Copy> {
    pub x: T,
    pub y: T,
    pub z: T
}

impl<T: PartialOrd + Copy> Vector3<T> {
    pub fn new(x: T, y: T, z: T) -> Vector3<T> {
        Vector3 {
            x,
            y,
            z
        }
    }
}

impl<T> Add for Vector3<T>
where T: PartialOrd + Copy + Add<Output = T> {

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
where T: PartialOrd + Copy + Sub<Output = T> {

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
where T: PartialOrd + Copy + Mul<Output = T> {

    type Output = Self;

    fn mul(self, other: Self) -> Self::Output {
        Self {
            x: self.x * other.x,
            y: self.y * other.y,
            z: self.z * other.z
        }
    }
}
