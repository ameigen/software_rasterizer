#include "Camera.h"

Eigen::Matrix4f Camera::_lookingAt()
{
    Vector3 _zAxis = Vector::normalize(_position - _direction);
    Vector3 _xAxis = Vector::normalize(Vector::cross(_up, _zAxis));
    Vector3 _yAxis = Vector::cross(_zAxis, _xAxis);
    
    Eigen::Matrix4f _viewMatrix = Eigen::Matrix4f::Zero();
    _viewMatrix <<
                _xAxis[0],                        _yAxis[0],                        _zAxis[0],                        0, 
                _xAxis[1],                        _yAxis[1],                        _zAxis[1],                        0,
                _xAxis[2],                        _yAxis[2],                        _zAxis[2],                        0,
                -Vector::dot(_xAxis, _position), -Vector::dot(_yAxis, _position), -Vector::dot(_zAxis, _position),    1;

    return _viewMatrix;
}
