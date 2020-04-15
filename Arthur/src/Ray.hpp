/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Ray.hpp
 */

#pragma once

#include "Point3D.hpp"

namespace raytracer 
{
    class Ray {

        public:
            Ray(const Eigen::Vector3d &direction, const math::Point3D<float> &origin);
            ~Ray();

            inline const Eigen::Vector3d &direction() const { return _direction; };

            inline const math::Point3D<float> &origin() const { return _origin; };

        private:
            Eigen::Vector3d _direction;
            math::Point3D<float> _origin;

        };
}