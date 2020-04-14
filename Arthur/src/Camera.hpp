/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.hpp
 */

#pragma once

#include "Point3D.hpp"

namespace raytracer
{
    class Camera {

        public:
            Camera(const math::Point3D<float> &pos);
            ~Camera();

        private:
            math::Point3D<float> _pos;
    };    
}