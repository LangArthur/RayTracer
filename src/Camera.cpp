/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.cpp
 */

#include "Camera.hpp"

raytracer::Camera::Camera(const std::vector<std::shared_ptr<IPrimitive>> &prim) :
    _pos({0, 0, 0}), _angle(45 * (M_1_PI / 180)), _bgColor({0, 0, 0}), _prim(prim)
{ }

raytracer::Camera::~Camera()
{ }

void raytracer::Camera::changeColor(raytracer::Color color)
{
    _bgColor = color;
}

std::vector<raytracer::Color> raytracer::Camera::getView(const int &imgX, const int &imgY)
{
    float z = -1;
    float imgRatio = imgX / imgY;
    float angleCoef = 1;
    // float angleCoef = std::tan(_angle / 2);
    math::Point3D<float> origin = {0, 0, 0};
    std::vector<raytracer::Color> pixels;
    for (float y = 0; y < imgY; y++) {
        for (float x = 0; x < imgX; x++) {
            float mx = (2 * (x + 0.5) / imgX - 1) * imgRatio * angleCoef;
            float my = (1 - 2 * (y + 0.5) / imgY) * angleCoef;
            Eigen::Vector3f direction(mx, my, z);
            raytracer::Ray r(direction, {0, 0, 0});
            pixels.push_back(getColor(r));
        }
    }
    return (pixels);
}

raytracer::Color raytracer::Camera::getColor(const Ray &r)
{
    for (auto &prim : _prim) {
        if (prim.get()->intersect(r)) {
            return (prim.get()->getColor());
        }
    }
    return (_bgColor);
}