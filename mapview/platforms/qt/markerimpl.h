#pragma once
#include "marker.h"
#include "util/types.h"
namespace Tangram{
class Map;
}

namespace ltd_mapview {

class MarkerImpl: public Marker
{
public:
    MarkerImpl(Tangram::Map* map);
    ~MarkerImpl();

    // Mark interface
private:
    virtual void setImage(const std::string &iconURI) override;
    virtual void setTitle(const std::string &title) override;
    virtual void setPosition(const Coordinate &coord) override;
    virtual void setVisible(bool visible) override;

private:
    Tangram::Map*       m_map;
    Tangram::MarkerID   m_iconID;   //use this marker to show icon
    Tangram::MarkerID   m_labelID;  //use this marker to show label

};

}
