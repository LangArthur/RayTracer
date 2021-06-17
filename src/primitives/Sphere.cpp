/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Sphere.cpp
 */

#include "Sphere.hpp"

raytracer::Sphere::Sphere(const cv::Point3f &center, const float &radius) : _center(center), _radius(radius), _color({0, 255, 0})
{ }

raytracer::Sphere::~Sphere()
{ }

bool raytracer::Sphere::intersect(const raytracer::Ray &ray)
{

//     float t = math::toVector(ray.origin(), _center).dot(ray.direction());

//     // intersection point the ray
//     Eigen::Vector3f p = ray.direction() * t;

//     float y = (math::toVector(_center) - p).norm();
//     if (y < _radius) {
//         return true;
//         // float x = sqrt(_radius * _radius - y * y);

//         // float t1 = t - x;
//         // float t2 = t + x;
//     } else {
//         return false;
//     }
//     // float a = 1;
//     // float b = 2 * ray.origin() * 
    return false;
}

void raytracer::Sphere::debug()
{
    std::cout << "Sphere:" << std::endl;
    std::cout << "Center: " << _center << "\tradius : " << _radius << std::endl;
}

const raytracer::Color &raytracer::Sphere::getColor()
{
     return (_color);
}
