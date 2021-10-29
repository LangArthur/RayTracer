/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) Rendere 2020 Arthur Lang
 * Renderer.cpp
 */

#include "Renderer.hpp"

raytracer::Renderer::Renderer()
{
}

raytracer::Renderer::~Renderer()
{
}

cv::Mat &raytracer::Renderer::render(const int &imgX, const int &imgY, const std::vector<std::shared_ptr<IPrimitive>> &prim,
                                     const raytracer::Camera &cam)
{
}