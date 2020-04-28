/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.hpp
 */

#pragma once

#include <Eigen/Dense>
#include <memory>
#include <vector>
#include <cmath>

#include "Point3D.hpp"
#include "IPrimitive.hpp"

namespace raytracer
{
    class Camera {

        public:
            Camera(const std::vector<std::shared_ptr<IPrimitive>> &prim);
            ~Camera();

            inline void changeColor(raytracer::Color color);

            std::vector<raytracer::Color> getView(const int &x, const int &y);
            raytracer::Color getColor(const Ray &y);

        private:
            math::Point3D<float> _pos;
            Eigen::Vector3f _lookAt;
            float _angle;
            raytracer::Color _bgColor;

            const std::vector<std::shared_ptr<IPrimitive>> &_prim;
    };    
}