/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Sphere.cpp
 */

#include "Sphere.hpp"

raytracer::Sphere::Sphere(const math::Point3D<float> &center, const float &radius) : _center(center), _radius(radius)
{ }

raytracer::Sphere::~Sphere()
{ }

bool raytracer::Sphere::intersect(const raytracer::Ray &ray, float &dist)
{
    float a = 1;
    glm::vec3 OC = math::toVector(ray.origin(), _center);
    float b = glm::dot(ray.direction(), OC);
    float c = glm::normalize(OC) - _radius * _radius

    float delta = (b * b) - (a * c)
    if (delta < 0)
        return false;
    
}