use crate::rendering;
use crate::props;

use image;
use image::GenericImage;

use crate::rendering::object_traits::Drawable;

/// Takes a scene in parameter and render it to an image with the image crate.
pub fn render(scene: &rendering::scene::Scene) -> Option<image::DynamicImage> {

    // Checking if their is something to render.
    if scene.objects.is_empty() {
        return None;
    }

    // Creating a new image object.
    let mut image = image::DynamicImage::new_rgb8(scene.width, scene.height);

    // Iterating trough the pixels of the image.
    for x in 0..scene.width {
        for y in 0..scene.height {
            render_pixel_on_image(x, y, scene, &mut image);
        }
    }
    Some(image)
}

fn render_pixel_on_image(x: u32, y: u32, scene: &rendering::scene::Scene, image: &mut image::DynamicImage) {
    // Tracing a ray.
    let ray = props::ray::Ray::create_prime(x, y, scene);

    // Calculating the closest distance between the camera and an object that the ray hit.
    let mut obj_to_render: Option<&Box<dyn Drawable>> = None;
    let mut curr_dist_min: Option<f64>                = None;

    for object in scene.objects.iter() {

        match object.hit(&ray) {
            Some(d) => match curr_dist_min {
                Some(cd) => if d < cd {
                    obj_to_render = Some(object);
                    curr_dist_min = Some(d);
                },
                None     => {
                    obj_to_render = Some(object);
                    curr_dist_min = Some(d);
                }
            },
            None => ()
        }
    }

    // Checking if the ray has hit a sphere.
    // (We will add more shapes in the futur)
    match obj_to_render {
        Some(obj_to_render) => {

            let color_to_render = obj_to_render.color();

            image.put_pixel(x, y, image::Rgba([
                color_to_render.r,
                color_to_render.g,
                color_to_render.b,
                color_to_render.a
            ]));
        },

        None => image.put_pixel(x, y, image::Rgba([0, 0, 0, 0]))
    }
}
