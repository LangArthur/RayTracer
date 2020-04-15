extern crate cgmath;
use cgmath::Vector3;

use raytracer::props;
use raytracer::rendering;

use image;
use image::GenericImageView;

#[test]
fn test_can_render_scene() {

    let scene = rendering::scene::Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        objects: vec![
            Box::new(rendering::sphere::Sphere::new(
                Vector3::new(0.0, 0.0, -3.0),
                1.0,
                props::color::Color {
                    r: 255,
                    g: 0,
                    b: 0,
                    a: 255
                }
            )),
            Box::new(rendering::sphere::Sphere::new(
                Vector3::new(-0.5, 0.0, -3.0),
                1.0,
                props::color::Color {
                    r: 0,
                    g: 0,
                    b: 255,
                    a: 255
                }
            )),
            Box::new(rendering::sphere::Sphere::new(
                Vector3::new(0.5, 0.0, -3.0),
                1.0,
                props::color::Color {
                    r: 0,
                    g: 255,
                    b: 0,
                    a: 255
                }
            ))
        ]
    };

    let img: image::DynamicImage = match rendering::renderer::render(&scene) {
        Some(image) => image,
        None => panic!("There is no object to render.")
    };
    img.save("test.png").unwrap();
    assert_eq!(scene.width, img.width());
    assert_eq!(scene.height, img.height());
}
