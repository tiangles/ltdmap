#pragma once
#include <string>

namespace ltd_mapview{

class Projection{
    bool fromScreen(int x, int y, double* latitude, double* longitude) const;
    bool toScreen(double latitude, double longitude, int* x, int* y) const;
};
}
