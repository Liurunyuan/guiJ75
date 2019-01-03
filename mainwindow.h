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
//char curve[12] = {0x5a,0x5a,0x01,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0xa5,0xa5};


namespace Ui {

class MainWindow;

}

typedef struct _Curve
{
    qint16 torque: 1;
    qint16 speed: 1;
    qint16 displacemet: 1;
    qint16 current: 1;
    qint16 voltage: 1;
    qint16 ff: 1;
    qint16 temperature: 1;
    qint16 accel: 1;

    qint16 z: 1;
    qint16 x: 1;
    qint16 c: 1;
    qint16 v: 1;
    qint16 k: 1;
    qint16 f: 1;
    qint16 p: 1;
    qint16 o: 1;
}Curve;

typedef struct
{
    qint16 low8 : 8;
    qint16 high8 :8;

}Var16Bit;

typedef union
{
    Var16Bit half;
    qint16 all;
    Curve bit;
}CurveStr;
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
    void initCustomPlot2();

    bool needToUnpack();
    bool needToUnpack2();
    void unpack();
    void unpack2();

//    void initTxDataDisplay();

//    void initRxDataDisplay();

public slots:
    void refreshLCD();
    void updatePlot();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_openButton_clicked();
    void on_testbtn_clicked();

    void on_actionAbout_how_to_use_triggered();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_actionCurve_config_triggered();

    void on_actionSystem_config_triggered();

    void on_actionDisplacement_triggered();

    void on_actionMotor_speed_triggered();

    void on_actionMotor_accel_triggered();

    void on_actionCurrent_triggered();

    void on_actionBus_voltage_triggered();

    void on_openButton_2_clicked();

    void on_SendBtn_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    static MainWindow* mainWindow;
    Ui::MainWindow *ui;
    Serialport* serialPort;
    Serialport* serialPortX;
    QTimer *timer1;
    QTimer *timer2;
    MyThread* task1;
    qint16 curveCommand;

    QQueue<QByteArray> sendStringQ;
    char curve[12] = {0x5a,0x5a,0x01,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0xa5,0xa5};
    char configPara[12] = {0x5a,0x5a,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa5,0xa5};
    CurveStr curveComm;
};


#endif // MAINWINDOW_H
