use cgmath::Vector3;
use raytracer::rendering::plane::Plane;
use raytracer::rendering::scene::Scene;
use raytracer::props::color::Color;
use raytracer::props::ray::Ray;

use image;
use image::GenericImageView;

#[test]
fn intersect_plane_test() {

    let scene = Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        objects: vec![
            Box::new(Plane {
                origin: Vector3::new(0.0, -3.0, -5.0),
                normal: Vector3::new(0.0, -1.0,  0.0),
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

    let ray = Ray::create_prime(900, 900, &scene);

    match scene.objects[0].hit(&ray) {
        Some(_) => assert!(true),
        None     => assert!(false)
    };
}

#[test]
fn do_not_intersect_plane_test() {

    let scene = Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        objects: vec![
            Box::new(Plane {
                origin: Vector3::new(0.0, -3.0, -5.0),
                normal: Vector3::new(0.0, -1.0,  0.0),
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

    let ray = Ray::create_prime(100, 200, &scene);

    match scene.objects[0].hit(&ray) {
        Some(_) => assert!(false),
        None     => assert!(true)
    };
}
