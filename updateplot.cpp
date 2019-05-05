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
    while(!isInterruptionRequested())
    {
        if(MainWindow::getInstance()->needToUnpack() == true)
        {
            mutex.lock();
            MainWindow::getInstance()->unpack();
            mutex.unlock();
        }
        if(MainWindow::getInstance()->needToUnpack2() == true)
        {
            MainWindow::getInstance()->unpack2();
        }
    }
}
