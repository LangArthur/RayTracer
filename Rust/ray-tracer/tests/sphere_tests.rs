use cgmath::Vector3;
use raytracer::rendering::sphere::Sphere;
use raytracer::rendering::scene::Scene;
use raytracer::props::color::Color;
use raytracer::props::ray::Ray;

#[test]
fn intersect_sphere_test() {

    let scene = Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        objects: vec![
            Box::new(Sphere {
                center: Vector3::new(0.0, 0.0, -5.0),
                radius: 2.0,
                color:  Color {
                    r: 255,
                    g: 255,
                    b: 255,
                    a: 255,
                }
            }
            )
        ]
    };

    let ray = Ray::create_prime(500, 500, &scene);

    match scene.objects[0].hit(&ray) {
        Some(_) => assert!(true),
        None    => assert!(false)
    };
}

#[test]
fn do_not_intersect_sphere_test() {

    let scene = Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        objects: vec![
            Box::new(Sphere {
                center: Vector3::new(0.0, 0.0, -5.0),
                radius: 1.0,
                color:  Color {
                    r: 255,
                    g: 255,
                    b: 255,
                    a: 255,
                }
            }
            )
        ]
    };

    let ray = Ray::create_prime(100, 100, &scene);

    match scene.objects[0].hit(&ray) {
        Some(_) => assert!(false),
        None    => assert!(true)
    };
}
