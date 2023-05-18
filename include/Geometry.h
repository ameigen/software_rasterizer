#pragma once
#include <cmath>
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <vector>

const size_t TRIANGLE_EDGES = 3;


template <typename T>
struct Vector2 
{
    T v[2];

    Vector2() 
        : v{0, 0} {}
    Vector2(T a, T b)
        : v{a, b} {}

    T x() const
    {
        return v[0];
    }

    T y() const
    {
        return v[1];
    }

    T magnitude() const
    {
        return sqrt((v[0]* v[0] + v[1]));
    }
    Vector2 operator+(Vector2& other) const 
    {
        return Vector2(v[0] + other[0], v[1] + other[1]);
    }

    Vector2 operator-(Vector2& other) const 
    {
        return Vector2(v[0] - other[0], v[1] - other[1]);
    }

    Vector2 operator*(T scalar) const 
    {
        return Vector2(v[0] * scalar, v[1] * scalar);
    }
    
    T operator*(const Vector2 &other) const 
    {
        T xProd = v[0] * other[0];
        T yProd = v[1] * other[1];
        return (xProd + yProd);
    }

    T& operator[](size_t index)
    {
        if (index >= 2)
            throw std::out_of_range("Index out of range");
        return v[index];        
    }
};

template <typename T>
struct Vector3 
{
    T v[3];

    Vector3()
        : v{0, 0, 0} {}
        
    Vector3(T a, T b, T c)
        : v{a, b, c} {}

    T x() const
    {
        return v[0];
    }

    T y() const
    {
        return v[1];
    }

    T z() const
    {
        return v[2];
    }

    T magnitude() const
    {
        return sqrt((v[0] * v[0]) + v[1] * v[1] + (v[2] * v[2]));
    }
    
    Vector3 operator+(Vector3& other) const 
    {
        return Vector3(v[0] + other[0], v[1] + other[1], v[2] + other[2]);
    }

    Vector3 operator-(Vector3& other) const 
    {
        return Vector3(v[0] - other[0], v[1] - other[1], v[2] - other[2]);
    }

    Vector3 operator*(T scalar) const 
    {
        return Vector3(v[0] * scalar,v[1] * scalar, v[2] * scalar);
    }

    Vector3 operator/(T scalar) const
    {
        return Vector3(v[0] / scalar,v[1] / scalar, v[2] / scalar);
    } 

    T operator*(const Vector3 &other) const 
    {
        T xProd = v[0] * other[0];
        T yProd = v[1] * other[1];
        T zProd = v[2] * other[2];
        return (xProd + yProd + zProd);
    }

    T& operator[](size_t index)
    {
        if (index >= 3)
            throw std::out_of_range("Index out of range");
        return v[index];        
    }
};

template <typename T>
struct Vector4
{
    T v[4];
    Vector4()
        : v{0, 0, 0, 0} {}
        
    Vector4(T a, T b, T c, T d)
        : v{a, b, c, d} {}

    Vector4(Vector3<T> &v)
        : v{v[0], v[1], v[2], 1} {}

    T x() const
    {
        return v[0];
    }

    T y() const
    {
        return v[1];
    }

    T z() const
    {
        return v[2];
    }

    T w() const
    {
        return v[3];
    }

    Vector3<T> toVec3() const
    {
        if (v[3] != 1 && v[3] != 0 )
            return Vector3<T>(v[0] /= v[3], v[1] /= v[3], v[2] /= v[3]);
    }

    T& operator[](size_t index)
    {
        if (index >= 4)
            throw std::out_of_range("Index out of range");
        return v[index];        
    }
};

template <typename T>
struct Triangle
{
    Vector3<T> edges[TRIANGLE_EDGES];

    Triangle()
        : edges{Vector3<T>(),
                Vector3<T>(),
                Vector3<T>()} {}

    Triangle(Vector3<T> a,
             Vector3<T> b,
             Vector3<T> c)
        : edges{a,
                b,
                c} {}
     
    Triangle(T a1, T a2, T a3,
             T b1, T b2, T b3,
             T c1, T  c2, T c3)
        : Triangle(Vector3<T>(a1, a2, a3),
                   Vector3<T>(b1, b2, b3),
                   Vector3<T>(c1, c2, c3)) {}

    const T& operator[](size_t index) const
    {
        if (index >= TRIANGLE_EDGES)
            throw std::out_of_range("Index out of range");
        return edges[index];        
    }
};

template <typename T>
struct Model
{
    std::vector<Triangle<T>> triangles;

    Model();

    Model(unsigned triCount)
        : triangles{std::vector<Triangle<T>>(triCount)} {}

    Model(std::vector<Triangle<T>> &tris)
        : triangles{tris} {}

    Model(const std::string filePath);

    const Triangle<T> operator[](size_t index) const
    {
        if (index >= triangles->size())
            throw std::out_of_range("Index out of range");
        return triangles[index];
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector2<T>& v) 
{
    os << "(" << v[0] << ", " << v[1] << ")";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Triangle<T>& t) 
{
    os << "(" << t.edges[0] << ", " << t.edges[1] << ", " << t.edges[2] << ")";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector3<T>& v) 
{
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Model<T>& m)
{
    for (auto &triangle : m.triangles)
        os << triangle << '\n';
    return os;
}

namespace Vector
{
    template <typename T>
    T dot(Vector3<T> a, Vector3<T> b) 
    {
        return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

    }

    template <typename T>
    Vector3<T> cross(Vector3<T> a, Vector3<T> b) 
    {
        T _x = a[1] * b[2] - a[2] * b[1];
        T _y = a[2] * b[0] - a[0] * b[2];
        T _z = a[0] * b[1] - a[1] * b[0];

        return Vector3<T>(_x, _y, _z);
    }

    template <typename T>
    Vector3<T> normalize(Vector3<T> vec)
    {
        return vec / vec.magnitude();
    }
}