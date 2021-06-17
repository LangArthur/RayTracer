/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.hpp
 */

#pragma once

#include <memory>
#include <vector>

#include "IPrimitive.hpp"

namespace raytracer
{
    class Camera {

        public:
            Camera();
            ~Camera();

            inline void changeColor(raytracer::Color color);

        private:
            cv::Point3f _pos;
            cv::Vec3f _lookAt;
            float _angle;
            raytracer::Color _bgColor;
    };    
}