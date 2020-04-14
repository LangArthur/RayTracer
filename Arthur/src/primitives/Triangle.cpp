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
    // Eigen::Matrix3f A;
    // Eigen::Vector3f b;
    // A << 1,2,3,  4,5,6,  7,8,10;
    // b << 3, 3, 4;
    // std::cout << "Here is the matrix A:\n" << A << std::endl;
    // std::cout << "Here is the vector b:\n" << b << std::endl;
    // Eigen::Vector3f x = A.colPivHouseholderQr().solve(b);
    // std::cout << "The solution is:\n" << x << std::endl;
    Eigen::Matrix3f system;
    Eigen::Vector3f unknown;
    system << _a.x(), _b.x(), _c.x(), _a.y(), _b.y(), _c.y(), _a.z(), _b.z(), _c.z();
    unknown << 1.6, 1.1, 1.5;
    Eigen::Vector3f x = system.colPivHouseholderQr().solve(unknown);
    std::cout << "The solution is:\n" << x << std::endl;
    return true;
}
