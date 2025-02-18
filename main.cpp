#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "singleton.h"
#include "observer.h"
#include "subject.h"
#include "client.h"
#include <QImageReader>
#include <QDebug>
#include "serialport.h"
#include "updateplot.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    updatePlot updatePlotThread(&w);
    updatePlotThread.start();

    return a.exec();
}
