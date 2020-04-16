/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) Raytracer 2020 Arthur Lang
 * Plan.cpp
 */

#include "Plan.hpp"

raytracer::Plan::Plan(const math::Point3D<float> &orientation, const Eigen::Vector3f &norm) : _orientation(orientation), _norm(norm), _color({255, 0, 0})
{ }

raytracer::Plan::~Plan()
{ }

bool raytracer::Plan::intersect(const Ray &ray)
{
    float denom = ray.direction().dot(_norm);
    if (denom > 1.e-6) {
        float t = (math::toVector(_orientation, ray.origin()).dot(_norm)) / denom;
        return (t >= 0);
    }
    return false;
}

cv::Vec<unsigned char, 3> raytracer::Plan::getColor()
{
    return (_color);
}
