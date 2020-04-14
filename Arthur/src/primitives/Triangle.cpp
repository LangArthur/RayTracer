/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Triangle.cpp
 */

#include "Triangle.hpp"

raytracer::Triangle::Triangle(const math::Point3D<float> &a, const math::Point3D<float> &b, const math::Point3D<float> &c) : _a(a), _b(b), _c(c)
{ }

bool raytracer::Triangle::intersect(const Ray& ray)
{
    // glm::vec3 unknown(-1, -7, -6);
    // glm::mat3 system(_a.x(), _b.x(), _c.x(), _a.y(), _b.y(), _c.y(), _a.z(), _b.z(), _c.z());
    return true;
}
