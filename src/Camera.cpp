/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.cpp
 */

#include "Camera.hpp"

raytracer::Camera::Camera() : _pos(0, 0, 0),  _angle((M_1_PI / 2))
{ }

raytracer::Camera::~Camera()
{ }

const raytracer::Ray raytracer::Camera::getRay(const int &x, const int &y)
{
    float z = -1; // negative axis orientation by convention
    float imgRatio = _pictDim.first / _pictDim.second;
    // float angleCoef = 1;
    float angleCoef = std::tan(_angle / 2);

    // normalize point (([0:1])) and then adjust it to screen space ([1:-1])
    float mx = (2 * (x + 0.5) / _pictDim.first - 1) * imgRatio * angleCoef;
    float my = (1 - 2 * (y + 0.5) / _pictDim.second) * angleCoef;
    cv::Vec3f rayDirection = {mx, my, z};
    return raytracer::Ray(cv::normalize(rayDirection) , {0, 0, 0});
}
