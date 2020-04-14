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
    // define the system equation
    Eigen::Matrix3f system;
    system << _a.x(), _b.x(), _c.x(), _a.y(), _b.y(), _c.y(), _a.z(), _b.z(), _c.z();
    // coordinate of intersection
    // to do : compute this part
    Eigen::Vector3f intersect(0.9, 1.9, 4.9);
    // resolving System
    Eigen::Vector3f res = system.colPivHouseholderQr().solve(intersect);
    if (res[0] > 0 && res[1] > 0 && res[2] > 0)
        return true;
    else
        return false;
}
