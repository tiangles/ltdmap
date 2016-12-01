#pragma once
#include <string>

namespace ltd_mapview{
class BoundingBox;

class Camera{
public:
    enum Type{
        PERSPECTIVE,
        ISOMETRIC,
        FLAT
    };

    double  m_latitude;
    double  m_longitude;
    double  m_zoom;
    double  m_rotation;
    double  m_tilt;
    Type    m_type;
};


class CameraFactory{
    Camera scrollCamera(Camera& cam, int x, int y);
    Camera createCamera(Camera& cam, BoundingBox& bb);
};

}
