#pragma once
#include <vector>

namespace ltd_mapview{

class Coordinate;
class BoundingBox;
typedef std::vector<Coordinate> Polyline;
class Marker;
class Style{
    enum EdgeType{
        Inherited,
        Solid,
        Dot,
        Dash
    };
    enum FillType{
        Inherited,
    };

    int         edgeSize;
    EdgeType    edgeType;
    int         edgeColor;

    int         fillColor;
    FillType    fillType;
};

class GeoGraphic{
    Style style;
};

class GeoLocation:public GeoGraphic{
    Marker      marker;
    Coordinate  position;
};

class GeoPolyline: public GeoGraphic{
    Polyline line;
};

class GeoPolygon: public GeoGraphic{
    Polyline                outer;
    std::vector<Polyline>   inners;
};
}
