#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include "serialport.h"
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QThread>

#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* getInstance();
    void updateSerialInfo();
    void initialUI();


    void initLcdNum();

    void initTimer1();

    void initTimer2();

    void initCustomPlot();

    void initTxDataDisplay();

    void initRxDataDisplay();

public slots:
    void refreshLCD();
    void updatePlot();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_openButton_clicked();
    void on_testbtn_clicked();

private:
    static MainWindow* mainWindow;
    Ui::MainWindow *ui;
    Serialport* serialPort;
    QTimer *timer1;
    QTimer *timer2;
    MyThread* task1;
};


#endif // MAINWINDOW_H
