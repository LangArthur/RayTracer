/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * main.cpp
 */

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "Scene.hpp"
#include "Plan.hpp"
#include "Sphere.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char const **argv)
{
    raytracer::Scene s;

    // math::Point3D<float> a({1, 2, 1});
    // math::Point3D<float> b({4, 3, 0});
    // math::Point3D<float> c({-3, 2, 1});
    // Eigen::Vector3f normal(0, 1, 0);
    // math::Point3D<float> p({0, -1, 0});
    // std::shared_ptr<raytracer::IPrimitive> plan = std::make_shared<raytracer::Plan>(p, normal);

    
    // math::Point3D<float> c({0, 0, 5});
    // std::shared_ptr<raytracer::IPrimitive> sph = std::make_shared<raytracer::Sphere>(c, 1);

    // s.push(sph);
    // s.push(plan);
    // s.debug();
    auto img = s.render(1920, 1080);

    // cv::imshow("Raytracer", img);
    // int k = cv::waitKey(0);
    // if (k == 's') {
    //     imwrite("starry_night.png", img);
    // }
    return 0;
}
