/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Renderer.hpp
 */

#pragma once

#include <opencv2/opencv.hpp>

constexpr const auto IMG_PATH = "./output.png";

namespace raytracer
{
    class Renderer {

        public:
            Renderer();
            ~Renderer();

            void createImage(const int &imgX, const int &imgY);
    };    
}