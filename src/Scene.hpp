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
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Ray.hpp"

namespace raytracer
{
    class Scene {
        public:
            /// \brief constructor
            Scene();
            /// \brief destructor
            ~Scene();

            /// \brief add an object to the scene
            /// \param obj a referecne on a primitive
            void push(const std::shared_ptr<IPrimitive> &obj);

            /// \brief process the image and
            /// \param imgX width of the output image
            /// \param imgY height of the output image
            // void render(const int &imgX, const int &imgY);
            /// \brief display divers information about the scene
            void debug();

        private:
            /*! vector containing all the primitives of the scene */
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            /*! The renderer for the scene */
            // Renderer _rend;
            /*! The camera of the scene */
            Camera _cam;
    };
}