#include "mapview.h"
#include <QSharedPointer>

namespace Tangram{
class MapWidget;
}
namespace ltd_mapview{
class Marker;

class MapViewImpl: public MapView
{
public:
    MapViewImpl();
    ~MapViewImpl();

private:
    void addListener(MapViewListener *listener) override;
    void setCamera(const Camera &cam, double duration) override;
    void addGeoGraphic(std::vector<GeoGraphic> geo) override;
    const Projection &getProjection() const override;
    void *getNativeWindow() override;
//    void enableLayer(std::string layerName) override;
//    void disableLayer(std::string layerName) override;
//    void enableGesture() override;
//    void disableGesture() override;
    std::shared_ptr<Marker> createMarker() override;

private:
    Tangram::MapWidget* m_mapWidget;
    Camera*             m_camera;
    Projection*         m_projection;

};
}
