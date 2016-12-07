#include <QApplication>
#include <QWidget>
#include "mapview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ltd_mapview::MapView* v = ltd_mapview::MapView::createInstance();
    QWidget* w = static_cast<QWidget* >(v->getNativeWindow());
    w->show();

    return app.exec();
}
