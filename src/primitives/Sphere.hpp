/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Sphere.hpp
 */

#pragma once

#include <ctgmath>

#include "IPrimitive.hpp"
#include "Point3D.hpp"

namespace raytracer
{
    class Sphere : public IPrimitive {

        public:
            Sphere(const math::Point3D<float> &center, const float &radius);
            ~Sphere();

            inline const math::Point3D<float> &center() const { return _center; };
            inline const float &radius() const { return _radius; };

            void debug() override;
            bool intersect(const Ray& ray) override;
            std::array<unsigned char, 3> getColor() override;

        private:
            math::Point3D<float> _center;
            float _radius;
            std::array<unsigned char, 3> _color;
    };
}