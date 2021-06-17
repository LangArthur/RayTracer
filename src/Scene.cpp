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

// void raytracer::Scene::render(const int &imgX, const int &imgY)
// {
//     _rend.createImage(imgX, imgY, _cam.getView(imgX, imgY));
// }

void raytracer::Scene::debug()
{
    std::cout << "Scene :\n" << "Number of primitives : " << _primitives.size() << std::endl;
    for (auto &prim : _primitives)
        prim.get()->debug();
}