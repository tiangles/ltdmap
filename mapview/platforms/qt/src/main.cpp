#include <QApplication>
#include <QWidget>
#include "mapview.h"
#include "marker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ltd_mapview::MapView* view = ltd_mapview::MapView::createInstance();
    QWidget* w = static_cast<QWidget* >(view->getNativeWindow());
    w->show();

    auto marker = view->createMarker("img/poi_icons_32.png", "hello marker");
    marker->setLocation(ltd_mapview::Coordinate(39.23748501586914, 117.13788604736328));
    marker->setVisible(true);

    return app.exec();
}
