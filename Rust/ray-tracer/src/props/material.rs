extern crate image;

use crate::props::color::Color;
use image::DynamicImage;

pub enum Texture {
    ColorTexture(Color),
    ImageTexture(DynamicImage)
}

impl Texture {

    pub fn color(&self) -> Color {

        match *self {
            Texture::ColorTexture(ref color)   => Color::clone(color),
            Texture::ImageTexture(ref _texture) => {
                Color {
                    r: 0.0,
                    g: 0.0,
                    b: 0.0,
                    a: 0.0
                }
            }
        }
    }
}

pub struct Material {

    pub texture: Texture,
    pub albedo:  f64,
}