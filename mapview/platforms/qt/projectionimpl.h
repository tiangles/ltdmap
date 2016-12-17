#pragma once
#include "projection.h"

namespace Tangram{
class Map;
}
namespace ltd_mapview{

class ProjectionImpl: public Projection
{
public:
    ProjectionImpl(Tangram::Map* map);

public:
    bool fromScreen(int x, int y, double *latitude, double *longitude) const override;
    bool toScreen(double latitude, double longitude, int *x, int *y) const override;

private:
    Tangram::Map*   m_map;
};

}
