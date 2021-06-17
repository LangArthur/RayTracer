/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Ray.hpp
 */

#pragma once

#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>

namespace raytracer 
{
    class Ray {

        public:
            Ray(const cv::Vec3f &direction, const cv::Point3f &origin);
            ~Ray();

            inline const cv::Vec3f &direction() const { return _direction; };

            inline const cv::Point3f &origin() const { return _origin; };

        private:
            cv::Vec3f _direction;
            cv::Point3f _origin;

        };
}