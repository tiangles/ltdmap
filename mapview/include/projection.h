#pragma once
#include <string>

namespace ltd_mapview{

class Projection{
public:
    virtual ~Projection(){}
    virtual bool fromScreen(int x, int y, double* latitude, double* longitude) const = 0;
    virtual bool toScreen(double latitude, double longitude, int* x, int* y) const = 0;
};
}
