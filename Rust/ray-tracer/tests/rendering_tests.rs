use raytracer::rendering::objects;
use image::GenericImageView;
use image;

pub fn render(scene: &objects::Scene) -> image::DynamicImage {
    image::DynamicImage::new_rgb8(scene.width, scene.height)
}

#[test]
fn test_can_render_scene() {

    let scene = objects::Scene {
        width: 800,
        height: 600,
        fov: 90.0,
        sphere: objects::Sphere {
            center: objects::Point {
                x: 0.0,
                y: 0.0,
                z: -5.0
            },
            radius: 1.0,
            color: objects::Color {
                r: 0,
                g: 255,
                b: 0,
                a: 255
            },
        }
    };

    let img: image::DynamicImage = render(&scene);
    assert_eq!(scene.width, img.width());
    assert_eq!(scene.height, img.height());
}
