#include "updateplot.h"
#include <QMutex>

QMutex mutex;

updatePlot::updatePlot(MainWindow* main)
{
    mainPlot = main;
}
updatePlot::~updatePlot()
{
    this->requestInterruption();
    this->quit();
    this->wait();
}

void updatePlot::run()
{
//    QThread::msleep(20);
    while(!isInterruptionRequested())
    {
        QThread::msleep(20);
        if(MainWindow::getInstance()->needToUnpack() == true)
        {
            mutex.lock();
            MainWindow::getInstance()->unpack();
            mutex.unlock();
        }
    }
}
