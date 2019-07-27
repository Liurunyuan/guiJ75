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
#include "ota.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    updatePlot updatePlotThread(&w);
    updatePlotThread.start();


    ota otaThread(&w);
    otaThread.start();

    return a.exec();
}
