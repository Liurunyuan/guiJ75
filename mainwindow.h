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
#define MAXCURVE 3


namespace Ui {

class MainWindow;

}

typedef struct _Curve
{
    qint16 maxCurrent: 1;
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

    void initRepeatTimer();

    void initCustomPlot();
    void initCustomPlot2();

    bool needToUnpack();
    bool needToUnpack2();
    void unpack();
    void unpack2();

    void drawCurrentPosition(double x, double y);

//    void initTxDataDisplay();

//    void initRxDataDisplay();

    void configCuveMenu();

public slots:
    void refreshLCD();
    void updatePlot();
    void repeatTimerPlot();
protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_openButton_clicked();

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

    void on_actionDisplacement2_triggered();

    void on_actionMotor_speed2_triggered();

    void on_actionMotor_accel2_triggered();

    void on_actionCurrent2_triggered();

    void on_actionBus_voltage2_triggered();

    void on_duty_editingFinished();

    void on_targetSpeed_editingFinished();

    void on_dutySpinBox_editingFinished();

    void on_targetSpeedSpinBox_editingFinished();

    void on_clearButton_clicked();

    void on_actionTemperatrue_triggered();

    void on_actionMacCurrent_triggered();

    void on_repeateBtn_clicked();

private:
    static MainWindow* mainWindow;
    Ui::MainWindow *ui;
    Serialport* serialPort;
    Serialport* serialPortX;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *repeatTimer;
    qint16 curveCommand;
    int curveCount[2];
    QQueue<QByteArray> sendStringQ;
    char curve[12]      = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x03,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char curve2[12]     = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x03,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char configPara[12] = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char duty[12]       = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x4f,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char targetSpeed[12]= {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x02,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char stateComm[12]  = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x01,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char clearAlarm[12] = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x04,(char)0x00,(char)0x01,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    //QByteArray curve[12] = {0x5a, 0x5a, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xa5, 0xa5};
    //QByteArray configPara[12] = {0x5a, 0x5a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0xa5};
    CurveStr curveComm;
    CurveStr curveComm2;
    int posX;
    int posY;
    int showTargetSpeed;
};


#endif // MAINWINDOW_H
