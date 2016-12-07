#include "markerimpl.h"
#include "tangram.h"
#include "mapwidget.h"
#include <QImage>
#include <QBuffer>
#include <QFile>
#include <QDebug>

using namespace ltd_mapview;

MarkerImpl::MarkerImpl(Tangram::Map* map)
    :m_map(map)
{
    m_iconID = m_map->markerAdd();
    m_labelID = m_map->markerAdd();
}

MarkerImpl::~MarkerImpl()
{
    m_map->markerRemove(m_iconID);
}

void MarkerImpl::setImage(const std::string &iconURI)
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

    m_map->markerSetBitmap(m_iconID, width, height, argb);

    const char* MARKER_ICON_STYLE = "{ style: 'points', color: 'white', size: [%1px, %1px], order: 100, collide: false }";
    QString iconStyle = QString(MARKER_ICON_STYLE).arg(width).arg(height);
    m_map->markerSetStyling(m_iconID, iconStyle.toStdString().c_str());

    delete[] argb;
}

void MarkerImpl::setTitle(const std::string &title)
{
    const char* MARKER_TEXT_STYLE = "{ style: 'text', text_source: 'function(){ return \"%1\"}', offset: [0px, 24px], text_wrap: false}";
    QString labelStyle = QString(MARKER_TEXT_STYLE).arg(title.c_str());
    qWarning()<<labelStyle;
    m_map->markerSetStyling(m_labelID, labelStyle.toStdString().c_str());

}

void MarkerImpl::setPosition(const Coordinate &coord)
{
    m_map->markerSetPoint(m_iconID, Tangram::LngLat(coord.longitude, coord.latitude));
    m_map->markerSetPoint(m_labelID, Tangram::LngLat(coord.longitude, coord.latitude));
}

void MarkerImpl::setVisible(bool visible)
{
    m_map->markerSetVisible(m_iconID, visible);
    m_map->markerSetVisible(m_labelID, visible);
}
