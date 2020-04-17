/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) Raytracer 2020 Arthur Lang
 * Plan.cpp
 */

#include "Plan.hpp"

raytracer::Plan::Plan(const math::Point3D<float> &orientation, const Eigen::Vector3f &norm) : _point(orientation), _norm(norm), _color({255, 0, 0})
{ }

raytracer::Plan::~Plan()
{ }

void raytracer::Plan::debug()
{
    std::cout << "Plan :" << std::endl;
    std::cout << "Normal:\n" << _norm << "\n" << "Point on the plan" << _point << std::endl;
}

bool raytracer::Plan::intersect(const Ray &ray)
{
    float denom = ray.direction().dot(_norm);
    if (denom > 1.e-6) {
        float t = (math::toVector(ray.origin(), _point).dot(_norm)) / denom; // possiblement une erreur ici
        return (t >= 0);
    }
    return false;
}

cv::Vec<unsigned char, 3> raytracer::Plan::getColor()
{
    return (_color);
}
