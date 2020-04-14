/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Scene.cpp
 */

#include "Scene.hpp"

raytracer::Scene::Scene()
{ }

void raytracer::Scene::push(const std::shared_ptr<IPrimitive> &obj)
{
    _primitives.push_back(obj);
}

void raytracer::Scene::render()
{ }