use raytracer::props::point::Point;

#[test]
fn new_point_test() {

    // Creating a point.
    let ptn_1 = Point::new(1, 25, 0);

    assert_eq!(ptn_1.x, 1);
    assert_eq!(ptn_1.y, 25);
    assert_eq!(ptn_1.z, 0);

    // Creating a point initialised at zero.
    let ptn_2: Point<i32> = Point::zero();

    assert_eq!(ptn_2.x, 0);
    assert_eq!(ptn_2.y, 0);
    assert_eq!(ptn_2.z, 0);
}

