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
//    w.show();
    w.showMaximized();

    updatePlot updatePlotThread(&w);
    updatePlotThread.start();

    Singleton::GetInstance()->singlePrint();

    Subject *subject = new Subject();
    Client client(subject);

    subject->SetVal(5);
    subject->notify();
    subject->notify();
    subject->notify();


//    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();
    return a.exec();
}
