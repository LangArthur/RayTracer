/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Plan.hpp
 */

#pragma once

#include <Eigen/Dense>

#include "IPrimitive.hpp"
#include "Point3D.hpp"

namespace raytracer
{
    class Plan : public IPrimitive {
        public:
            Plan(const math::Point3D<float> &orientation, const Eigen::Vector3f &norm);
            ~Plan();

            void debug() override;
            bool intersect(const Ray &ray) override;
            cv::Vec<unsigned char, 3> getColor() override;

        private:
            math::Point3D<float> _point;
            Eigen::Vector3f _norm;
            cv::Vec<unsigned char, 3> _color;
    };
}