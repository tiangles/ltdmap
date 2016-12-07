#pragma once
#include "ltdtypes.h"
#include <string>

namespace ltd_mapview {

class Marker{
public:
    virtual ~Marker(){}

public:
    virtual void setImage(const std::string& iconURI) = 0;
    virtual void setPosition(const Coordinate& coord) = 0;
    virtual void setTitle(const std::string& title) = 0;
    virtual void setVisible(bool visible) = 0;
};
}
