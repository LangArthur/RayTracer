/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Scene.cpp
 */

#include "Scene.hpp"

raytracer::Scene::Scene() : _bgColor({0, 0, 0})
{ }

raytracer::Scene::~Scene()
{ }

void raytracer::Scene::push(const std::shared_ptr<IPrimitive> &obj)
{
    _primitives.push_back(obj);
}

void raytracer::Scene::render(const int &imgX, const int &imgY)
{
    float z = 1;
    float imgRatio = imgX / imgY;
    math::Point3D<float> origin = {0, 0, 0};
    std::vector<cv::Vec<unsigned char, 3>> pixels;
    for (float y = 0; y < imgY; y++) {
        for (float x = 0; x < imgX; x++) {
            float mx = 2 * ((x + 0.5) / imgX) - 1 * imgRatio;
            float my = 1 - 2 * ((y + 0.5) / imgY);
            Eigen::Vector3f direction(mx, my, z);
            raytracer::Ray r(direction, {0, 0, 0});
            pixels.push_back(getColor(r));
        }
    }

    _rend.createImage(imgX, imgY, pixels);
}

void raytracer::Scene::debug()
{
    std::cout << "Scene :\n" << "Number of primitives : " << _primitives.size() << std::endl;
}

cv::Vec<unsigned char, 3> raytracer::Scene::getColor(const Ray &r)
{
    for (auto &prim : _primitives) {
        if (prim.get()->intersect(r))
            return (prim.get()->getColor());
    }
    return (_bgColor);
}