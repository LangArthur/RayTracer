/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Ray.cpp
 */

#include "Ray.hpp"

raytracer::Ray::Ray(const Eigen::Vector3f &direction, const math::Point3D<float> &origin) : _direction(direction), _origin(origin)
{ }

raytracer::Ray::~Ray()
{ }
