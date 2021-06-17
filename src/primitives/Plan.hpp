/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Plan.hpp
 */

#pragma once

#include "IPrimitive.hpp"

namespace raytracer
{
    class Plan : public IPrimitive {
        public:
            Plan(const cv::Point3f &orientation, const cv::Vec3f &norm);
            ~Plan();

            void debug() override;
            bool intersect(const Ray &ray) override;
            const raytracer::Color &getColor() override;

        private:
            cv::Point3f _point;
            cv::Vec3f _norm;
            raytracer::Color _color;
    };
}