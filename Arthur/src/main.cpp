/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * main.cpp
 */

#include <iostream>

#include "Scene.hpp"
#include "Triangle.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char const **argv)
{
    raytracer::Scene s;
    s.debug();

    math::Point3D<float> a({1, 2, 1});
    math::Point3D<float> b({4, 3, 0});
    math::Point3D<float> c({-3, 2, 1});
    std::shared_ptr<raytracer::IPrimitive> tri = std::make_shared<raytracer::Triangle>(a, b, c);

    s.push(tri);
    s.debug();
    s.render(1920, 1080);
    return 0;
}
