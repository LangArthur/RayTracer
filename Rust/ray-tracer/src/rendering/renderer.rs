use crate::rendering;
use crate::props;

use image;
use image::GenericImage;

/// Takes a scene in parameter and render it to an image with the image crate.
pub fn render(scene: &rendering::scene::Scene) -> image::DynamicImage {

    let mut image = image::DynamicImage::new_rgb8(scene.width, scene.height);

    // Iterating trough the pixels of the image.
    for x in 0..scene.width {
        for y in 0..scene.height {
            render_pixel_on_image(x, y, scene, &mut image);
        }
    }
    image
}

fn render_pixel_on_image(x: u32, y: u32, scene: &rendering::scene::Scene, image: &mut image::DynamicImage) {

    // Tracing a ray.
    let ray = props::ray::Ray::create_prime(x, y, scene);

    // Calculating the closest distance between the camera and an object that the ray hit.
    let mut closest_distance = -1.0;
    let mut color_rendered_object = props::color::Color {r: 0, g: 0, b: 0, a: 0};

    for object in scene.objects.iter() {

        match object.hit(&ray) {
            Some(d) => if closest_distance == -1.0 || d < closest_distance {
                closest_distance = d;
                color_rendered_object = object.color();
            },
            None => ()
        }
    }

    // Checking if the ray has hit a sphere.
    // (We will add more shapes in the futur)
    if closest_distance != -1.0 {
        image.put_pixel(x, y, image::Rgba([
            color_rendered_object.r,
            color_rendered_object.g,
            color_rendered_object.b,
            color_rendered_object.a
        ]));
    } else {
        image.put_pixel(x, y, image::Rgba([0, 0, 0, 0]));
    }
}
