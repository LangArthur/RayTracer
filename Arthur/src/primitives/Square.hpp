/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Square.hpp
 */

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"

namespace raytracer
{
    class Square : public IPrimitive {

        public:
            Square(const math::Point3D<float> &origin, float size);
            ~Square() override;

            inline const float &size() { return _size; };
            inline const math::Point3D<float> &origin() { return _origin; };

        private:
            math::Point3D<float> _origin;
            float _size;
    };
}