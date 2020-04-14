/*
 * Created on Tue Apr 14 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Scene.hpp
 */

#pragma once

#include <vector>
#include <memory>

#include "IPrimitive.hpp"

namespace raytracer
{
    class Scene {
        public:
            Scene();
            ~Scene();

            void push(const std::shared_ptr<IPrimitive> &obj);
            void render();

        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
    };
}