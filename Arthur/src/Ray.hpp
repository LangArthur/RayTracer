/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Ray.hpp
 */

#include <glm/glm.hpp>

#include "Point3D.hpp"

namespace raytracer {

    class Ray {

        public:
            Ray(glm::vec3 direction, math::Point3D<float> origin);
            ~Ray();

            inline const glm::vec3 &direction() const { return _direction; };

            inline const math::Point3D<float> &origin() const { return _origin; };

        private:
            glm::vec3 _direction;
            math::Point3D<float> _origin;

        };
}