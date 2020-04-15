package ray

import java.awt.image.BufferedImage
import javax.imageio.ImageIO
import java.io.File
import java.nio.Buffer

import Vec3._
import Render._
import Ray._
import Color.Color

object Main
{
    def write(data: Array[Color], file: File): Unit = {
        val img = new BufferedImage(Render.WIDTH, Render.HEIGHT, BufferedImage.TYPE_INT_RGB)
        for {
            x <- 0 until Render.WIDTH
            y <- 0 until Render.HEIGHT
        } img.setRGB(x, y, data(x * y + x).toInt())
        ImageIO.write(img, "png", file)
    }

    def main(args: Array[String]): Unit = {
        if (args.length == 1)
            write(Render.render(), new File(args(0)))
    }
}
