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

            bool intersect(const Ray &ray) override;

        private:
            math::Point3D<float> _orientation;
            Eigen::Vector3f _norm;
    };
}