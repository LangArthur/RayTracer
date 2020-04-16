/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Scene.cpp
 */

#include "Scene.hpp"

raytracer::Scene::Scene()
{ }

raytracer::Scene::~Scene()
{ }

void raytracer::Scene::push(const std::shared_ptr<IPrimitive> &obj)
{
    _primitives.push_back(obj);
}

void raytracer::Scene::render(const int &imgX, const int &imgY)
{
    // scale x and y on -1 1
    float scaleY = imgX / 3;
    float scaleZ = imgY / 3;
    float x = 1;
    math::Point3D<float> origin = {0, 0, 0};
    for (float z = 1; z >= -1; z -= scaleZ) {
        for (float y = -1; y <= 1; y += scaleY) {
            // raytracer::Ray r();
        }
    }

    _rend.createImage(imgX, imgY);
}

void raytracer::Scene::debug()
{
    std::cout << "Scene :\n" << "Number of primitives : " << _primitives.size() << std::endl;
}