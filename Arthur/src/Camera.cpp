/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Camera.cpp
 */

#include "Camera.hpp"

raytracer::Camera::Camera(const math::Point3D<float> &pos) : _pos(pos)
{
}

raytracer::Camera::~Camera()
{
}
