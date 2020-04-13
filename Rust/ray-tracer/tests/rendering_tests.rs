extern crate cgmath;

use raytracer::rendering;
use raytracer::props;
use crate::rendering::object_traits::Intersect;

use cgmath::Vector3;
use image;
use image::GenericImageView;
use image::GenericImage;

pub fn render(scene: &rendering::scene::Scene) -> image::DynamicImage {

    let mut image = image::DynamicImage::new_rgb8(scene.width, scene.height);

    for x in 0..scene.width {
        for y in 0..scene.height {

            let ray = props::ray::Ray::create_prime(x as f64, y as f64, scene);

            if scene.sphere.hit(&ray) {
                image.put_pixel(x, y, image::Rgba([
                    scene.sphere.color.r,
                    scene.sphere.color.g,
                    scene.sphere.color.b,
                    scene.sphere.color.a
                ]));
            } else {
                image.put_pixel(x, y, image::Rgba([0, 0, 0, 0]));
            }
        }
    }
    image
}

#[test]
fn test_can_render_scene() {

    let scene = rendering::scene::Scene {
        width: 1000,
        height: 1000,
        fov: 90.0,
        sphere: rendering::sphere::Sphere {
            center: Vector3::new(-2.5, 2.5, -5.0),
            radius: 1.0,
            color: props::color::Color {
                r: 255,
                g: 0,
                b: 0,
                a: 255
            },
        }
    };

    let img: image::DynamicImage = render(&scene);
    img.save("fuckoff.png").unwrap();
    assert_eq!(scene.width, img.width());
    assert_eq!(scene.height, img.height());
}
