/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Sphere.hpp
 */

#pragma once

#include "IPrimitive.hpp"

namespace raytracer
{
    class Sphere : public IPrimitive {

        public:
            Sphere(const cv::Point3f &center, const float &radius);
            ~Sphere();

            inline const cv::Point3f &center() const { return _center; };
            inline const float &radius() const { return _radius; };

            void debug() override;
            bool intersect(const Ray& ray) override;
            const raytracer::Color &getColor() override;

        private:
            cv::Point3f _center;
            float _radius;
            raytracer::Color _color;
    };
}