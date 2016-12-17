#include "projectionimpl.h"
#include "tangram.h"

using namespace ltd_mapview;

ProjectionImpl::ProjectionImpl(Tangram::Map* map)
    :m_map(map)
{

}

bool ProjectionImpl::fromScreen(int x, int y, double *latitude, double *longitude) const
{
    m_map->screenPositionToLngLat(x, y, longitude, latitude);
}

bool ProjectionImpl::toScreen(double latitude, double longitude, int *x, int *y) const
{
    double _x;
    double _y;
    m_map->lngLatToScreenPosition(longitude, latitude, &_x,  &_y);
    *x = (int)_x;
    *y = (int)_y;
}
