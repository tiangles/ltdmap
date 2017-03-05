#pragma once
#include "marker.h"
#include "tangram/util/types.h"
namespace Tangram{
class Map;
}

namespace ltd_mapview {

class MarkerImpl: public Marker
{
public:
    MarkerImpl(Tangram::Map* map, const std::string &iconURI, const std::string &title);
    ~MarkerImpl();

private:
    void createMarker(const std::string &iconURI, const std::string &title);
    // Mark interface
private:
    virtual void setLocation(const Coordinate &coord) override;
    virtual void setVisible(bool visible) override;

private:
    Tangram::Map*       m_map;
    Tangram::MarkerID   m_ID;

};

}
