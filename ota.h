#ifndef OTA_H
#define OTA_H

#include <QThread>
#include <QDebug>
#include "mainwindow.h"

class ota: public QThread
{
public:
    ota(MainWindow*);
    ~ota();
    void run();


    QByteArray hexStringtoByteArray(QString hex);


private:
    MainWindow* mainPlot;
};
#endif // OTA_H
