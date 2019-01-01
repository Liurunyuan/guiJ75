#ifndef UPDATEPLOT_H
#define UPDATEPLOT_H
#include <QThread>
#include <QDebug>
#include "mainwindow.h"

class updatePlot: public QThread
{
public:
    updatePlot(MainWindow*);
    ~updatePlot();
    void run();

private:
    MainWindow* mainPlot;
};

#endif // UPDATEPLOT_H
