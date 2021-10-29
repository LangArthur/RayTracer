/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.hpp
 */

#pragma once

#include <memory>
#include <vector>
#include <initializer_list>

#include "IPrimitive.hpp"
#include "Ray.hpp"

namespace raytracer
{
    class Camera {

        public:
            Camera();
            ~Camera();

            inline void changeColor(raytracer::Color color);
            inline void setPictureDimension(int x, int y) { _pictDim = {x, y}; }

            const raytracer::Ray getRay(const int &x, const int &y);

        private:
            std::pair<int, int> _pictDim; // dimension of the picture
            cv::Point3f _pos; // position of the camera
            float _angle;
            // float _focal; // distance between projection plane and projection point : might be use later
    };    
}