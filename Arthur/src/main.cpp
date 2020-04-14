/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * main.cpp
 */

#include <Eigen/Dense>

// #include "Triangle.hpp"
#include "Point3D.hpp"
// #include "Ray.hpp"

int main(int argc, char const **argv)
{
    math::Point3D<float> a(-3.0, 6.0, 3.0);
    math::Point3D<float> b(2.0, -6.0, -4.0);
    math::Point3D<float> c(-1.0, 7.0, 4.0);
    // raytracer::Triangle tri(a, b, c);

    // math::Point3D<float> origin(0.0, 3.0, 1.0);
    // raytracer::Ray r(dir, origin);

    // tri.intersect(r);
    return 0;
}
