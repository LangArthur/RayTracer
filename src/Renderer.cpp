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
    cv::Mat img(imgY, imgX, CV_8UC3, cv::Scalar(0, 0, 0));
    // int i = 0;
    // cv::MatIterator_<cv::Vec3b> it, end = img.end<cv::Vec3b>();
    // for (it = img.begin<cv::Vec3b>(); it != end; it++) {
    //     (*it)[0] = pix[i][0];
    //     (*it)[1] = pix[i][1];
    //     (*it)[2] = pix[i][2];
    //     i++;
    // }
    cv::imwrite(IMG_PATH, img);
}