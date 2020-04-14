/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Triangle.cpp
 */

#include "Triangle.hpp"

raytracer::Triangle::Triangle(math::Point3D<float> a, math::Point3D<float> b, math::Point3D<float> c) : _a(a), _b(b), _c(c)
{ }

bool raytracer::Triangle::intersect(const Ray& ray, float &dist)
{

}
