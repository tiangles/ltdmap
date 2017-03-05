#include "markermpl.h"
#include "tangram/tangram.h"
#include "mapwidget.h"
#include <QImage>
#include <QBuffer>
#include <QFile>
#include <QDebug>

using namespace ltd_mapview;

MarkerImpl::MarkerImpl(Tangram::Map* map, const std::string &iconURI, const std::string &title)
    :m_map(map)
{
    m_ID = m_map->markerAdd();
    createMarker(iconURI, title);
}

MarkerImpl::~MarkerImpl()
{
    m_map->markerRemove(m_ID);
}

void MarkerImpl::createMarker(const std::string &iconURI, const std::string &title)
{
    QImage img(QString(iconURI.c_str()));
    int width = img.width();
    int height = 36;
    auto argb = new unsigned int [width * height];
    for(int h=height-1; h>-1; --h){
        for(int w=0; w<width; ++w){
            int pix = img.pixelColor(w, h).rgba();
            int pb = (pix >> 16) & 0xff;
            int pr = (pix << 16) & 0x00ff0000;
            int pix1 = (pix & 0xff00ff00) | pr | pb;
            argb[w + h*width] = pix1;
        }
    }
    m_map->markerSetBitmap(m_ID, width, height, argb);
    delete[] argb;

    static const char* MARKER_STYLE_TEMPLATE =
            "{ style: 'points',"
            " color: 'white',"
            " size: [%1px, %2px],"
            " order: 100,"
            " collide: false,"
            " text: {"
                " text_source: 'function(){ return \"%3\"}',"
                " priority: 100 } }";
    QString iconStyle = QString(MARKER_STYLE_TEMPLATE).arg(width).arg(height).arg(title.c_str());
    m_map->markerSetStyling(m_ID, iconStyle.toStdString().c_str());
}

void MarkerImpl::setLocation(const Coordinate &coord)
{
    m_map->markerSetPoint(m_ID, Tangram::LngLat(coord.longitude, coord.latitude));
}

void MarkerImpl::setVisible(bool visible)
{
    m_map->markerSetVisible(m_ID, visible);
}
