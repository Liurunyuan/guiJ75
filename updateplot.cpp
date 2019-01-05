#include "updateplot.h"

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
            MainWindow::getInstance()->unpack();
        }
        if(MainWindow::getInstance()->needToUnpack2() == true)
        {
            MainWindow::getInstance()->unpack2();
        }
    }
}
