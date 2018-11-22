#include <QApplication>
#include <mainwindow.h>
#include "openglheader.h"
#include "openglviewer.h"
#include <QtGui>
#include <QLabel>
#include <QTreeView>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgQt/GraphicsWindowQt>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

    MainWindow mainWin;

    mainWin.showMaximized();

    return app.exec();
}
