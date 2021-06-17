/*
 * Created on Thu Apr 16 2020
 *
 * Copyright (c) Raytracer 2020 Arthur Lang
 * Plan.cpp
 */

#include "Plan.hpp"

raytracer::Plan::Plan(const cv::Point3f &orientation, const cv::Vec3f &norm) : _point(orientation), _norm(norm), _color({255, 0, 0})
{ }

raytracer::Plan::~Plan()
{ }

void raytracer::Plan::debug()
{
    std::cout << "Plan :" << std::endl;
    std::cout << "Normal:\n" << _norm << "\n" << "Point on the plan" << _point << std::endl;
}

bool raytracer::Plan::intersect(const Ray &ray)
{
    return false;
}

const raytracer::Color &raytracer::Plan::getColor()
{
    return (_color);
}
