extern crate cgmath;
use cgmath::InnerSpace;

use crate::rendering;
use crate::props;
use crate::rendering::object_traits::Drawable;
use crate::miscellaneous::progressbar::ProgressBar;
use crate::rendering::light::Light;

use image;
use image::GenericImage;

/// Takes a scene in parameter and render it to an image with the image crate.
pub fn render(scene: &rendering::scene::Scene) -> Option<image::DynamicImage> {

    // Checking if their is something to render.
    if scene.objects.is_empty() {
        return None;
    }

    // Creating a new image object.
    let mut image = image::DynamicImage::new_rgb8(scene.width, scene.height);

    // Dividing the work with four threads, this needs to be dynamic.
    // TODO : Make the number of thread running customizable.
    render_part_of_image(0, scene.width, &scene, &mut image);

    Some(image)
}

fn render_part_of_image(start: u32,
                        end: u32,
                        scene: &rendering::scene::Scene,
                        image: &mut image::DynamicImage) {

    let mut bar = ProgressBar::new((end * scene.height) as f64, 20);

    // Iterating trough the pixels of the image.
    for x in start..end {
        for y in 0..scene.height {
            render_pixel_on_image(x, y, scene, image);
        }
        bar.inc(scene.height as f64);
    }
}

fn render_pixel_on_image(x: u32,
                         y: u32,
                         scene: &rendering::scene::Scene,
                         image: &mut image::DynamicImage) {
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
            None    => ()
        }
    }

    // Checking if the ray has hit a sphere.
    // (We will add more shapes in the futur)
    match obj_to_render {
        Some(obj_to_render) => {

            let color_to_render = shadows(&ray, obj_to_render, &scene.lights, curr_dist_min.unwrap());
    
            image.put_pixel(x, y, image::Rgba([
                (color_to_render.r * 255.0) as u8,
                (color_to_render.g * 255.0) as u8,
                (color_to_render.b * 255.0) as u8,
                (color_to_render.a * 255.0) as u8
            ]));
        },

        None => image.put_pixel(x, y, image::Rgba([0, 0, 0, 0]))
    }
}

fn shadows(ray: &props::ray::Ray,
           object: &Box<dyn Drawable>,
           lights: &Vec<Light>,
           distance: f64) -> props::color::Color {

    let ray_hit = ray.origin + (ray.direction * distance);
    let surface_normal = object.surface_normal(ray_hit);
    let light_power = surface_normal.dot(-lights[0].direction).max(0.0);
    let light_reflected = object.albedo().intensity / std::f64::consts::PI;

    props::color::Color {
        r: object.color().r * lights[0].color.r * light_power * light_reflected,
        g: object.color().g * lights[0].color.g * light_power * light_reflected,
        b: object.color().b * lights[0].color.b * light_power * light_reflected,
        a: object.color().a * lights[0].color.a * light_power * light_reflected
    }
}