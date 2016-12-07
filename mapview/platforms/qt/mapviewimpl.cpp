#include "mapviewimpl.h"
#include "camera.h"
#include "mapwidget.h"
#include "tangram.h"
#include "markerimpl.h"

using namespace ltd_mapview;

MapView* MapView::createInstance(){
    return new MapViewImpl();
}

MapViewImpl::MapViewImpl()
{
    m_mapWidget = new Tangram::MapWidget(NULL);
    m_mapWidget->initialize("scene.yaml");
}

MapViewImpl::~MapViewImpl()
{

}

void MapViewImpl::addListener(MapViewListener */*listener*/)
{

}

void MapViewImpl::setCamera(const Camera & cam, double duration)
{
    bool posChanged = false;
    bool rotationChanged = false;
    bool zoomChanged = false;
    bool tiltChanged = false;
    if(cam.m_latitude != -999.0)
    {
        m_camera->m_latitude = cam.m_latitude;
        posChanged = true;
    }
    if(cam.m_longitude != -999.0)
    {
        m_camera->m_longitude = cam.m_longitude;
        posChanged = true;
    }

    if(cam.m_rotation != -999.0){
        m_camera->m_rotation = cam.m_rotation;
        rotationChanged = true;
    }

    if(cam.m_zoom != -999.0){
        m_camera->m_zoom = cam.m_zoom;
        rotationChanged = true;
    }

    if(cam.m_tilt != -999.0){
        m_camera->m_tilt = cam.m_tilt;
        rotationChanged = true;
    }

    if(posChanged) {
        m_mapWidget->getMap()->setPositionEased(m_camera->m_longitude, m_camera->m_latitude, duration);
    }
    if(rotationChanged) {
        m_mapWidget->getMap()->setRotationEased(m_camera->m_rotation, duration);
    }
    if(zoomChanged){
        m_mapWidget->getMap()->setZoomEased(m_camera->m_zoom, duration);
    }
    if(tiltChanged){
        m_mapWidget->getMap()->setTiltEased(m_camera->m_tilt, duration);
    }

}

void MapViewImpl::addGeoGraphic(std::vector<GeoGraphic> /*geo*/)
{

}

const Projection &MapViewImpl::getProjection() const
{
    return *m_projection;
}

void *MapViewImpl::getNativeWindow()
{
    return m_mapWidget;
}

std::shared_ptr<Marker> MapViewImpl::createMarker(const std::string& iconURI,
                                                  const std::string& title)
{
    return std::make_shared<MarkerImpl>(m_mapWidget->getMap(), iconURI, title);
}

//void MapViewImpl::enableLayer(std::string /*layerName*/)
//{

//}

//void MapViewImpl::disableLayer(std::string /*layerName*/)
//{

//}

//void MapViewImpl::enableGesture()
//{

//}

//void MapViewImpl::disableGesture()
//{

//}
