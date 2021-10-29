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

cv::Mat raytracer::Scene::render(const int &imgX, const int &imgY)
{
    cv::Mat img(imgY, imgX, CV_8UC3, cv::Scalar(0, 0, 0));
    _cam.setPictureDimension(imgX, imgY); // set image dimension to camera

    for (float y = 0; y < imgY; y++) {
        for (float x = 0; x < imgX; x++) {
            raytracer::Ray r = _cam.getRay(x, y);
            // pixels.push_back(getColor(r));
        }
    }

// raytracer::Color raytracer::Scene::getColor(const Ray &r)
// {
//     for (auto &prim : _prim) {
//         if (prim.get()->intersect(r)) {
//             return (prim.get()->getColor());
//         }
//     }
//     return (_bgColor);
// }


    // int i = 0;
    // cv::MatIterator_<cv::Vec3b> it, end = img.end<cv::Vec3b>();
    // for (it = img.begin<cv::Vec3b>(); it != end; it++) {
    //     (*it)[0] = pix[i][0];
    //     (*it)[1] = pix[i][1];
    //     (*it)[2] = pix[i][2];
    //     i++;
    // }
    // cv::imwrite(IMG_PATH, img);
    return img;
}

void raytracer::Scene::debug()
{
    std::cout << "Scene :\n" << "Number of primitives : " << _primitives.size() << std::endl;
    for (auto &prim : _primitives)
        prim.get()->debug();
}