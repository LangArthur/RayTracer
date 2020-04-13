use raytracer::props::vector::Vector3;

#[test]
fn new_vector3d_test() {

    // Creating a 3d vector.
    let vec3 = Vector3::new(1, 25, 0);

    assert_eq!(vec3.x, 1);
    assert_eq!(vec3.y, 25);
    assert_eq!(vec3.z, 0);
}

#[test]
fn vectors3d_sum_test() {

    // Creating a 2d vector.
    let vec3_1 = Vector3 {
        x: 42,
        y: 2,
        z: 5,
    };

    let vec3_2 = Vector3 {
        x: 22,
        y: 7,
        z: 14,
    };

    let vec3_sum = vec3_1 + vec3_2;

    assert_eq!(vec3_sum.x, 64);
    assert_eq!(vec3_sum.y, 9);
    assert_eq!(vec3_sum.z, 19);
}

#[test]
fn vectors3d_sub_test() {

    // Creating a 2d vector.
    let vec3_1 = Vector3 {
        x: 2,
        y: 2,
        z: 5,
    };

    let vec3_2 = Vector3 {
        x: 10,
        y: 5,
        z: 3,
    };

    let vec3_sub = vec3_1 - vec3_2;

    assert_eq!(vec3_sub.x, -8);
    assert_eq!(vec3_sub.y, -3);
    assert_eq!(vec3_sub.z, 2);
}

#[test]
fn vectors3d_mul_test() {

    // Creating a 2d vector.
    let vec3_1 = Vector3 {
        x: 2,
        y: 2,
        z: 5,
    };

    let vec3_2 = Vector3 {
        x: 10,
        y: 5,
        z: 3,
    };

    let vec3_sum = vec3_1 * vec3_2;

    assert_eq!(vec3_sum.x, 20);
    assert_eq!(vec3_sum.y, 10);
    assert_eq!(vec3_sum.z, 15);
}
