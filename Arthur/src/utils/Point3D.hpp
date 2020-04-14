/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) Raytracer 2020 Arthur Lang
 * Point3D.hpp
 */

#pragma once

#include <glm/glm.hpp>

namespace math {

    template<typename T>

    class Point3D {

        public:
            Point3D(T x, T y, T z) : _x(x), _y(y), _z(z) {};
            ~Point3D() {};

            inline const T x() const { return _x; };
            inline const T y() const { return _y; };
            inline const T z() const { return _z; };

            bool operator==(const Point3D<T> &other)
            {
                return (other.x() == _x && other.y() == y && other.z() == z);
            }

            bool operator!=(const Point3D<T> &other)
            {
                return (other.x() != _x || other.y() != y || other.z() != z);
            }

            Point3D<T> operator+(const Point3D<T> &other)
            {
                Point3D<T> res(_x + other.x(), _y + other.y(), _z + other.z());
                return res;
            }

            Point3D<T> operator-(const Point3D<T> &other)
            {
                Point3D<T> res(_x - other.x(), _y - other.y(), _z - other.z());
                return res;
            }

            Point3D<T> operator*(const Point3D<T> &other)
            {
                Point3D<T> res(_x * other.x(), _y * other.y(), _z * other.z());
                return res;
            }

            glm::vec3 convert() const
            {
                glm::vec3 res(_x, _y, _z);;
                return res;
            }

        private:
            T _x;
            T _y;
            T _z;
    };

        template<typename T>
        static glm::vec3 toVector(const Point3D<T> &fst, const Point3D<T> &sec)
        {
            glm::vec3 res(sec.x() - fst.x(), sec.y() - fst.y(), sec.z() - fst.z());
            return res;
        }
}