/*
 * Created on Thu Apr 09 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * IPrimitive.hpp
 */

#pragma once

#include "Ray.hpp"

namespace raytracer
{
    class IPrimitive {

        public:
            virtual ~IPrimitive() = default;

            virtual bool intersect(const Ray& ray) = 0;
            // virtual std::pair<int> getColor() = 0;
    };
}