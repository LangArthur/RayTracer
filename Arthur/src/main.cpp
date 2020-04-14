/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * main.cpp
 */

#include <Eigen/Dense>

#include "Triangle.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"

int main(int argc, char const **argv)
{
    math::Point3D<float> a(2, 1, 1);
    math::Point3D<float> b(2, 2, 2);
    math::Point3D<float> c(4, 4, 2);
    raytracer::Triangle tri(a, b, c);

    Eigen::Vector3d dir(1, -2, 3);
    math::Point3D<float> origin(0.0, 3.0, 1.0);
    raytracer::Ray r(dir, origin);

    tri.intersect(r);
    return 0;
}
