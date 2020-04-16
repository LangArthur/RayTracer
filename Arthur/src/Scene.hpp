/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Scene.hpp
 */

#pragma once

#include <vector>
#include <memory>
#include <opencv2/opencv.hpp>

#include "IPrimitive.hpp"
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Ray.hpp"

namespace raytracer
{
    class Scene {
        public:
            Scene();
            ~Scene();

            void push(const std::shared_ptr<IPrimitive> &obj);
            void render(const int &imgX, const int &imgY);
            void debug();

            cv::Vec<unsigned char, 3> getColor(const Ray &y);

        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            Renderer _rend;
            // Camera _cam;

            cv::Vec<unsigned char, 3> _bgColor;
    };
}