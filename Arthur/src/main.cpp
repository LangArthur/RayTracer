/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * main.cpp
 */

#include <Eigen/Dense>
#include <iostream>

#include "Triangle.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"

int main(int argc, char const **argv)
{
    math::Point3D<float> a(5, 2, 5);
    math::Point3D<float> b(-3, 3, 5);
    math::Point3D<float> c(4, -4, 4);
    raytracer::Triangle tri(a, b, c);

    Eigen::Vector3d dir(1, -2, 3);
    math::Point3D<float> origin(0.0, 3.0, 1.0);
    raytracer::Ray r(dir, origin);

    if (tri.intersect(r))
        std::cout << "Intersect" << std::endl;
    else
        std::cout << "Don't intersect" << std::endl;
    return 0;
}
