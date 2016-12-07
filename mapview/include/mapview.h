#pragma once
#include <string>
#include <vector>
#include <memory>

namespace ltd_mapview{

class Camera;
class Projection;
class GeoGraphic;
class Marker;

class MapViewListener{
    virtual void onMapViewCamearChanged(const Camera& cam) = 0;
    virtual void onMapViewLongPressed() = 0;
};

class MapView{
public:
    static MapView* createInstance();
    virtual ~MapView(){}

public:
    virtual void addListener(MapViewListener*  listener) = 0;
    virtual void setCamera(const Camera& cam, double duration) = 0;
    virtual void addGeoGraphic(std::vector<GeoGraphic> geo) = 0;
    virtual const Projection& getProjection() const = 0;
    virtual void* getNativeWindow() = 0;
    virtual std::shared_ptr<Marker> createMarker() = 0;
};
}
