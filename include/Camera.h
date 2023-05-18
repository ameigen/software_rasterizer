#pragma once
#include <Eigen/Dense>

#include "Geometry.h"
class Camera
{
    private:
        Vector3<float> _position,
                       _direction,
                       _up;
        
        Eigen::Matrix4f _lookingAt();
    
    public:
        Camera()
                :   _position(Vector3<float>(0, 0, 0)),
                    _direction(Vector3<float>(0, 1, 0)),
                    _up(Vector3<float>(1, 0, 0)) {}

        Camera(Vector3<float> position,
               Vector3<float> direction,
               Vector3<float> up)
                : _position(position),
                 _direction(direction),
                 _up(up) {}

        template <typename T>
        Vector3<T> pointToCameraSpace(Vector3<T> &v);

};