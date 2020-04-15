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

void raytracer::Renderer::createImage(const int &imgX, const int &imgY)
{
    cv::Mat img(imgY, imgX, CV_8U);
    std::cout << img << std::endl;
    // cv::imwrite(IMG_PATH, img);
}