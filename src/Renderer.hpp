/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Renderer.hpp
 */

#pragma once

#include <opencv2/opencv.hpp>
#include <memory>

#include "IPrimitive.hpp"
#include "Camera.hpp"

constexpr const auto IMG_PATH = "./output.png";

namespace raytracer
{
    class Renderer {

        public:
            Renderer();
            ~Renderer();

            cv::Mat &render(const int &imgX, const int &imgY, const std::vector<std::shared_ptr<IPrimitive>> &prim, const raytracer::Camera &cam);
    };
}