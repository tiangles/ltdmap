#pragma once
#include "ltdtypes.h"
#include <string>

namespace ltd_mapview {

class Marker{
public:
    virtual ~Marker(){}

public:
    virtual void setVisible(bool visible) = 0;
    virtual void setLocation(const Coordinate& location) = 0;
};
}
