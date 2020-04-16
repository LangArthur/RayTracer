/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) Raytracer 2020 Arthur Lang
 * Plan.cpp
 */

#include "Plan.hpp"

raytracer::Plan::Plan(const math::Point3D<float> &orientation, const Eigen::Vector3f &norm) : _orientation(orientation), _norm(norm)
{ }

raytracer::Plan::~Plan()
{ }

bool raytracer::Plan::intersect(const Ray &ray)
{
    float denom = ray.direction().dot(_norm);
    if (denom > 1.e-6) {
        float t = math::toVector(ray.origin(), _orientation).dot(_norm) / denom;
        return (t >= 0);
    }
    return false;
}