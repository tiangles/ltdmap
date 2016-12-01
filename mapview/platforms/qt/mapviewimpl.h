#include "mapview.h"

namespace Tangram{
class MapWidget;
}
namespace ltd_mapview{
class MapViewImpl: public MapView
{
public:
    MapViewImpl();
    ~MapViewImpl();

private:
    void addListener(MapViewListener *listener);
    void setCamera(const Camera &cam, double duration);
    void addGeoGraphic(std::vector<GeoGraphic> geo);
    const Projection &getProjection() const;
    void *getNativeWindow();
    void enableLayer(std::string layerName);
    void disableLayer(std::string layerName);
    void enableGesture();
    void disableGesture();

private:
    Tangram::MapWidget* m_mapWidget;
    Camera*             m_camera;
    Projection*         m_projection;
};
}
