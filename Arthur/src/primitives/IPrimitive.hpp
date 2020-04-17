/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * IPrimitive.hpp
 */

#pragma once

#include <opencv2/opencv.hpp>

#include "Ray.hpp"

namespace raytracer
{
    class IPrimitive {

        public:
            virtual ~IPrimitive() = default;

            virtual void debug() = 0;
            virtual bool intersect(const Ray& ray) = 0;
            virtual cv::Vec<unsigned char, 3> getColor() = 0;
    };
}