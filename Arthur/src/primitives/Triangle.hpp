/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Triangle.hpp
 */

#pragma once

#include <iostream>

#include "IPrimitive.hpp"
#include "Point3D.hpp"

namespace raytracer 
{
    class Triangle : public IPrimitive {
        public:
            Triangle(const math::Point3D<float> &a, const math::Point3D<float> &b, const math::Point3D<float> &c);
            ~Triangle() = default;

            inline const math::Point3D<float> &a() { return _a; };
            inline const math::Point3D<float> &b() { return _b; };
            inline const math::Point3D<float> &c() { return _c; };

            bool intersect(const Ray& ray) override;

        private:
            math::Point3D<float> _a;
            math::Point3D<float> _b;
            math::Point3D<float> _c;
    };
}