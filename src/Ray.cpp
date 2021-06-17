/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Ray.cpp
 */

#include "Ray.hpp"

raytracer::Ray::Ray(const cv::Vec3f &direction, const cv::Point3f &origin) : _direction(direction), _origin(origin)
{ }

raytracer::Ray::~Ray()
{ }
