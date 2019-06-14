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
#include <QFileDialog>
#include <QTextStream>

#include "mythread.h"
//char curve[12] = {0x5a,0x5a,0x01,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0xa5,0xa5};
#define MAXCURVE 5


namespace Ui {

class MainWindow;

}

typedef struct _Curve
{
    qint16 maxCurrent: 1;
    qint16 speed: 1;
    qint16 targetSpeed: 1;
    qint16 duty: 1;
    qint16 vol: 1;
    qint16 temp: 1;
    qint16 largestCurrent: 1;
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

    void drawCurrentPosition(double x, double y);

    void configCuveMenu();

public slots:
    void refreshLCD();
    void updatePlot();
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

    void on_actionMotor_speed_triggered();


    void on_SendBtn_clicked();


    void on_targetSpeedSpinBox_editingFinished();

    void on_clearButton_clicked();

    void on_actionDuty_triggered();

    void on_actionTargetSpeed_triggered();

    void on_actionCurrent_2_triggered();

    void on_actionTemp_triggered();

    void on_actionVol_triggered();

    void on_actionLargeestCurrent_triggered();

private:
    static MainWindow* mainWindow;
    Ui::MainWindow *ui;
    Serialport* serialPort;
    Serialport* serialPortX;
    QTimer *timer1;
    QTimer *timer2;
    qint16 curveCommand;
    int curveCount[2];
    QQueue<QByteArray> sendStringQ;
    char curve[12]      = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x03,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char curve2[12]     = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x03,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char configPara[12] = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char duty[12]       = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x4f,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
    char kp[12]         = {(char)0x5a,(char)0x5a,(char)0x01,(char)0x00,(char)0x00,(char)0x4b,(char)0x00,(char)0x00,(char)0x00,(char)0x00,(char)0xa5,(char)0xa5};
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
    QFile* file;
};


#endif // MAINWINDOW_H
