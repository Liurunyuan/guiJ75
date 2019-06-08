#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMutex>
extern QMutex mutex;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWindow = this;
    ui->setupUi(this);

    this->setGeometry(400, 100, 1295, 540);
    this->menuBar()->show();

    this->posX = 0;
    this->posY = 0;


    initialUI();

    initTimer1();

    initTimer2();


    updateSerialInfo();
    ui->SendBtn->setStyleSheet("QPushButton {background-color:green;}");

    this->curveCommand = 0;
    this->curveComm.all = 0;
    this->curveComm2.all = 0;

    this->curveCount[0] = 4;
    this->curveCount[1] = 0;

    ui->tabWidget->setTabText(0, "曲线绘制");

    configCuveMenu();

    ui->dockWidget->setMinimumSize(150,300);
    ui->dockWidget->setWindowTitle("串口设置");

    ui->dockWidget->setStyleSheet("QDockWidget {background-color:white;}");

    ui->systemconfig->setMinimumSize(150,300);
    ui->systemconfig->setStyleSheet("QDockWidget {background-color:red;"
                                    "color:red;"
                                    "border:2px outset white;"
                                    "}");
    //ui->systemconfig->setFeatures(QDockWidget::NoDockWidgetFeatures);



    addDockWidget(Qt::LeftDockWidgetArea, ui->dockWidget);

    ui->dockWidget->setStyleSheet("QDockWidget{color: black;}");
    ui->systemconfig->setStyleSheet("QDockWidget{color: black;}");
    QFont ft("Microsoft Yahei", 12, 75);
    ui->dockWidget->setFont(ft);
    ui->systemconfig->setFont(ft);
    ui->systemconfig->setWindowTitle("曲线显示/隐藏");


    ui->label->setStyleSheet("QLabel{color: red;}");
    ui->label_2->setStyleSheet("QLabel{color: red;}");
    ui->label_3->setStyleSheet("QLabel{color: red;}");
    ui->label_4->setStyleSheet("QLabel{color: red;}");
    ui->label_5->setStyleSheet("QLabel{color: red;}");
}

MainWindow::~MainWindow()
{
    delete timer1;
    delete timer2;
    delete serialPort;
//    delete file;
    delete ui;
    qDebug() << "bye";
}
void MainWindow::configCuveMenu()
{
    ui->actionMotor_speed->setChecked(false);
    ui->actionCurrent_2->setChecked(true);
    ui->actionTargetSpeed->setChecked(true);
    ui->actionMotor_speed->setChecked(true);
    ui->actionDuty->setChecked(true);
}
void MainWindow::initCustomPlot()
{
    ui->widget->show();
    //ui->widget->setBackground(QBrush(QColor(0, 0, 0, 20)));
    ui->widget->legend->setVisible(true);
    ui->widget->legend->setBrush(QColor(255,255,255,0));//legend背景色设为白色但背景透明，允许图像在legend区域可见

    //ui->widget->xAxis->setLabel("x");
    ui->widget->xAxis->setRange(0,10);
    ui->widget->xAxis->grid();


    //ui->widget->yAxis->setLabel("y");
    ui->widget->yAxis->setRange(-500,12000);

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::green));
    //ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(0)->rescaleAxes();


    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::white));
    //ui->widget->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(1)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(Qt::red));
    //ui->widget->graph(2)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    //ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->widget->graph(2)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(3)->setPen(QPen(Qt::yellow));
    //ui->widget->graph(3)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(3)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(4)->setPen(QPen(Qt::blue));
    //ui->widget->graph(4)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(4)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(5)->setPen(QPen(Qt::darkRed));
//    ui->widget->graph(5)->setBrush(QBrush(QColor(0, 0, 100, 20)));
    ui->widget->graph(5)->rescaleAxes();

    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(false);



    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    //ui->widget->setFixedSize(1051,351);
    //ui->widget->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->widget->xAxis2->setBasePen(QPen(Qt::white, 1));
    ui->widget->yAxis2->setBasePen(QPen(Qt::white, 1));
    ui->widget->xAxis2->setTickPen(QPen(Qt::white, 1));
    ui->widget->yAxis2->setTickPen(QPen(Qt::white, 1));
    ui->widget->xAxis2->setSubTickPen(QPen(Qt::white, 1));
    ui->widget->yAxis2->setSubTickPen(QPen(Qt::white, 1));
    ui->widget->xAxis2->setTickLabelColor(Qt::white);
    ui->widget->yAxis2->setTickLabelColor(Qt::white);
    ui->widget->xAxis2->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget->yAxis2->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget->xAxis2->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget->yAxis2->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget->xAxis2->grid()->setSubGridVisible(true);
    ui->widget->yAxis2->grid()->setSubGridVisible(true);
    ui->widget->xAxis2->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget->yAxis2->grid()->setZeroLinePen(Qt::NoPen);
//    ui->widget->xAxis2->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->widget->yAxis2->setUpperEnding(QCPLineEnding::esSpikeArrow);


    ui->widget->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->widget->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->widget->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->widget->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->widget->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget->xAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->widget->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);


    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->widget->xAxis->setTicker(timeTicker);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->widget->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->widget->axisRect()->setBackground(axisRectGradient);

    ui->widget->setWindowOpacity(0.1);

    ui->widget->graph(0)->setName("电流");
    ui->widget->graph(1)->setName("电机转速");
    ui->widget->graph(2)->setName("电机目标转速");
    ui->widget->graph(3)->setName("占空比");
    ui->widget->graph(4)->setName("温度");
    ui->widget->graph(5)->setName("电压");

//    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
//    timeTicker->setTimeFormat("%h:%m:%s");
//    ui->widget->xAxis->setTicker(timeTicker);
    //customPlot->axisRect()->setupFullAxesBox();
    ui->widget->replot();
}

void MainWindow::initCustomPlot2()
{


}

bool MainWindow::needToUnpack()
{
    if(this->serialPort->needUnpackData() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MainWindow::needToUnpack2()
{
    if(this->serialPortX->needUnpackData() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::unpack()
{
    this->serialPort->unpackData();
}

void MainWindow::unpack2()
{
    this->serialPortX->unpackData();
}

void MainWindow::drawCurrentPosition(double x, double y)
{
    QImage image("C:/Project/qtProject/bakserialqt/image/miaozhun.jpeg");
    QRectF target(0.0, 0.0, 250.0, 250.0);
    QRectF source(0.0, 0.0, 1000.0, 1000.0);

    y = this->posY;
    x = this->posX;
    y = (y*500)/65535;
    x = (x*500)/65535;

    for(int i = 0; i < 50; ++i)
    {
        for(int j = 0; j < 50; ++j)
        {
            image.setPixel(QPoint(i+475+x, j+475+y),qRgb(255,0,0));
        }
    }

}
void MainWindow::updateSerialInfo()
{
    serialPort = new Serialport();
    serialPortX = new Serialport();

    serialPort->scanPort();
    serialPortX->scanPort();

    for(auto it : serialPort->getAvailablePort())
    {
        ui->comBox->addItem(it);
    }

    for(auto it : serialPortX->getAvailablePort())
    {

    }
}

void MainWindow::initLcdNum()
{

}

void MainWindow::initTimer1()
{
    timer1 = new QTimer(this);
    timer1->setInterval(1000);
    connect(timer1, SIGNAL(timeout()), this, SLOT(refreshLCD()));
    timer1->start();
}

void MainWindow::initTimer2()
{
    timer2 = new QTimer(this);
    timer2->setInterval(40);
    connect(timer2, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer2->start();
}



void MainWindow::initialUI()
{
    initLcdNum();
    initCustomPlot();
    initCustomPlot2();
}

void MainWindow::updatePlot()
{

    QByteArray tmpbak;
    char* tmp;
//    static int key = 0;
    static qint16 y = 0;
    int len;
    unsigned char yh;
    unsigned char yl;
    static int ct = 0;
    static qint16 alarminfo = 0;
    static qint16 alarminfobak = -1;

    static qint16 systemState = 4;
    static qint16 systemStatebak = -1;
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;

    ct++;

    if(ct > 5){
        mutex.lock();
        this->serialPort->clearReadQ();
        mutex.unlock();
        ct = 0;
    }

    if(this->serialPort->isReadQEmpty() != 1)
    {
        file->open(QIODevice::ReadWrite|QIODevice::Append |QIODevice::Text );
        QTextStream stream(file);
        tmpbak = this->serialPort->getDisplayArray();
        tmp = tmpbak.data();

        yh = tmp[6];
        yl = tmp[7];
        y = (yh << 8) + yl;
        alarminfo = y;

        stream << "Time:" << key*1000;
        stream << "     Alarm:" << alarminfo;
        if(alarminfo != alarminfobak)
        {

            if(alarminfo == 0)
            {
                ui->alarmInfo->setText("No Alarm");
                ui->lineEdit->setText("软件电流正常");
                ui->lineEdit_2->setText("电压正常");
                ui->lineEdit_3->setText("温度正常");
                ui->lineEdit_4->setText("软件正常");
                ui->lineEdit_5->setText("硬件电流检测正常");
                ui->lineEdit->setStyleSheet("QLineEdit {background-color:white;}");
                ui->lineEdit_2->setStyleSheet("QLineEdit {background-color:white;}");
                ui->lineEdit_3->setStyleSheet("QLineEdit {background-color:white;}");
                ui->lineEdit_4->setStyleSheet("QLineEdit {background-color:white;}");
                ui->lineEdit_5->setStyleSheet("QLineEdit {background-color:white;}");
            }
            if((alarminfo & 0x0001) == 0x0001)
            {
                ui->alarmInfo->setText("over current");
                ui->lineEdit->setText("软件过流");
                ui->lineEdit->setStyleSheet("QLineEdit {background-color:red;}");
            }
            if((alarminfo & 0x0002) == 0x0002)
            {
                ui->alarmInfo->setText("over voltage");
                ui->lineEdit_2->setText("电压异常");
                ui->lineEdit_2->setStyleSheet("QLineEdit {background-color:red;}");
            }
            if((alarminfo & 0x0004) == 0x0004)
            {
                ui->alarmInfo->setText("over temperature");
                ui->lineEdit_3->setText("温度异常");
                ui->lineEdit_3->setStyleSheet("QLineEdit {background-color:red;}");
            }
            if((alarminfo & 0x0008) == 0x0008)
            {
                ui->alarmInfo->setText("software error");
                ui->lineEdit_4->setText("软件故障");
                ui->lineEdit_4->setStyleSheet("QLineEdit {background-color:red;}");
            }
            if((alarminfo & 0x0010) == 0x0010)
            {
                ui->alarmInfo->setText("init error");
            }
            if((alarminfo & 0x0020) == 0x0020)
            {
                ui->alarmInfo->setText("GPIO14 error");
                ui->lineEdit_5->setText("硬件过流");
                ui->lineEdit_5->setStyleSheet("QLineEdit {background-color:red;}");
            }
            if((alarminfo & 0x0040) == 0x0040)
            {
                ui->alarmInfo->setText("GPIO15 error");
            }
            alarminfobak = alarminfo;
        }

        yh = tmp[9];
        yl = tmp[10];
        y = (yh << 8) + yl;
        systemState = y;
        if(systemState != systemStatebak)
        {
            switch(systemState){
            case 0:
                ui->lineEdit_6->setText("系统处于未知状态");
                break;
            case 1:
                ui->lineEdit_6->setText("系统处于运行状态");
                break;
            case 2:
                ui->lineEdit_6->setText("系统处于停止状态");
                break;
            case 3:
                ui->lineEdit_6->setText("系统处于报警状态");
                break;
            case 4:
                ui->lineEdit_6->setText("系统处于 初始化状态");
                break;
            default:
                ui->lineEdit_6->setText("系统处于未定义状态");
                break;
            }

            systemStatebak = systemState;
        }


        len = tmp[2];
        for(int i = 2; i < len; ++i)
        {
            switch(tmp[5+i*3]){
            case 0:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;
                ui->widget->graph(0)->addData(key,y);
                stream << "     Current:" << y;
                break;
            case 1:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;
                ui->MotorSpeed->setValue(y);

                ui->widget->graph(1)->addData(key,y);
                stream << "     Speed:" << y;
                break;

            case 2:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(2)->addData(key,y);
                stream << "     Target speed:" << y;
                break;

            case 3:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (qint16)((yh << 8) + yl);
                ui->currentDuty->setValue(y);

                ui->widget->graph(3)->addData(key,y);
                stream << "     Duty:" << y;
                break;
            case 4:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (qint16)((yh << 8) + yl);

                ui->widget->graph(4)->addData(key,y);
                break;

            case 5:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (qint16)((yh << 8) + yl);

                ui->widget->graph(5)->addData(key,y);
                break;
                break;
            default:
                break;
            }
        }
        if(len > 2)
        {
            ui->widget->xAxis->setRange(key, 8, Qt::AlignRight);
            ui->widget->replot();
//            ++key;
        }
        stream << "\n";
        file->close();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QImage image(10,10,QImage::Format_RGB32);
    QPainter p(this);


    //    p.drawPixmap(0,0,width(), height(), QPixmap("/home/sean/Pictures/heike2.jpg"));
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    return true;

}

MainWindow* MainWindow::getInstance()
{
    if(mainWindow == NULL)
    {
        mainWindow = new MainWindow();
    }
    return mainWindow;

}

void MainWindow::refreshLCD()
{
    QDateTime dateTime = QDateTime::currentDateTime();

}

MainWindow* MainWindow::mainWindow = NULL;

void MainWindow::on_openButton_clicked()
{
     QString fileName = QFileDialog::getOpenFileName(this,tr("选择日志文件"),"",tr("TXT(*.txt)")); //选择路径
    qDebug() << fileName;
    file = new QFile(fileName);
    if(file->open(QIODevice::ReadWrite|QIODevice::Append |QIODevice::Text ))
    {
       QTextStream stream(file);
       stream << "current" << "     " << "temperature " << "\r\n";
       file->close();

    }
    if(ui->openButton->text() == "open")
    {
        if(serialPort->configPort(true,ui->comBox->currentText()) == true)
        {
           ui->openButton->setText("close");
        }
        else
        {
        }
    }
    else
    {
        if(serialPort->configPort(false,ui->comBox->currentText()))
        {
           ui->openButton->setText("open");
        }
    }
}


void MainWindow::on_actionAbout_how_to_use_triggered()
{
     //QMessageBox::about(NULL, "提示", "help");
    if(ui->actionAbout_how_to_use->isChecked())
    {
        qDebug() << "about how to use checked";
    }
    else
    {
        qDebug() << "about how to use not checked";
    }

}

void MainWindow::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
        ui->widget->graph(0)->setVisible(true);
    }
    else
    {
        ui->widget->graph(0)->setVisible(false);
    }
}

void MainWindow::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked())
    {
        ui->widget->graph(1)->setVisible(true);
    }
    else
    {
        ui->widget->graph(1)->setVisible(false);
    }
}

void MainWindow::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked())
    {
        ui->widget->graph(2)->setVisible(true);
    }
    else
    {
        ui->widget->graph(2)->setVisible(false);
    }
}

void MainWindow::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked())
    {
        ui->widget->graph(3)->setVisible(true);
    }
    else
    {
        ui->widget->graph(3)->setVisible(false);
    }
}

void MainWindow::on_actionCurve_config_triggered()
{
    if(ui->actionCurve_config->isChecked() == true)
    {
        addDockWidget(Qt::RightDockWidgetArea, ui->systemconfig);
        qDebug() << "curve config";
        ui->systemconfig->show();
    }
    else
    {
        ui->systemconfig->hide();
    }

}

void MainWindow::on_actionSystem_config_triggered()
{
    if(ui->actionSystem_config->isChecked() == true)
    {
        addDockWidget(Qt::RightDockWidgetArea, ui->dockWidget);
        qDebug() << "curve config";
        ui->dockWidget->show();
    }
    else
    {
        ui->dockWidget->hide();
    }
}



void MainWindow::on_actionMotor_speed_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_speed->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionMotor_speed->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for motor speed";
        this->curveComm.bit.speed = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle motor speed";

        this->curveComm.bit.speed = 0;

        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }
}



void MainWindow::on_SendBtn_clicked()
{
    qDebug() << "start button clicked";
    qint16 crc;
    QByteArray send_data;

    if(ui->SendBtn->text() == "Start")
    {
        stateComm[7] = 1;
        stateComm[6] = 0;
        crc = this->serialPort->calCrc(0, stateComm + 5, 3);

        stateComm[9] = (char)crc;
        stateComm[8] = (char)(crc >> 8);

        send_data.append(stateComm,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
        ui->SendBtn->setText("Stop");
        ui->SendBtn->setStyleSheet("QPushButton {background-color:red;}");
    }
    else
    {
        stateComm[7] = 2;
        stateComm[6] = 0;
        crc = this->serialPort->calCrc(0, stateComm + 5, 3);

        stateComm[9] = (char)crc;
        stateComm[8] = (char)(crc >> 8);

        send_data.append(stateComm,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
        ui->SendBtn->setText("Start");
        ui->SendBtn->setStyleSheet("QPushButton {background-color:green;}");
    }
}




void MainWindow::on_targetSpeedSpinBox_editingFinished()
{
    static int dutybak = -1;
    qDebug() << "set target speed spin box";
    qint16 crc;
    QByteArray send_data;
    CurveStr value;

    value.all = ui->targetSpeedSpinBox->text().toInt();

    if(value.all == dutybak){
        qDebug() << "same value, don't setting";
        return;
    }

    dutybak = value.all;

    targetSpeed[7] = value.half.low8;
    targetSpeed[6] = value.half.high8;
    crc = this->serialPort->calCrc(0, targetSpeed + 5, 3);

    targetSpeed[9] = (char)crc;
    targetSpeed[8] = (char)(crc >> 8);

    send_data.append(targetSpeed,12);
    qDebug() << send_data.toHex();
    this->serialPort->sendData(send_data);
    this->serialPort->sendData(send_data);
//    this->serialPortX->sendData(send_data);
//    this->serialPortX->sendData(send_data);

}

void MainWindow::on_clearButton_clicked()
{
    qDebug() << "clear alarm info";
    qint16 crc;
    QByteArray send_data;

    crc = this->serialPort->calCrc(0, clearAlarm + 5, 3);

    clearAlarm[9] = (char)crc;
    clearAlarm[8] = (char)(crc >> 8);

    send_data.append(clearAlarm,12);
    qDebug() << send_data.toHex();
    this->serialPort->sendData(send_data);
    this->serialPort->sendData(send_data);

}




void MainWindow::on_actionDuty_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionDuty->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionDuty->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for current duty";

        this->curveComm.bit.duty = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);

    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle current duty";
        this->curveComm.bit.duty = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }
}

void MainWindow::on_actionTargetSpeed_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionTargetSpeed->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionTargetSpeed->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for target speed";

        this->curveComm.bit.targetSpeed = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);

    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle target speed";
        this->curveComm.bit.targetSpeed = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }

}

void MainWindow::on_actionCurrent_2_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionCurrent_2->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionCurrent_2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for current";

        this->curveComm.bit.maxCurrent = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);

    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle current";
        this->curveComm.bit.maxCurrent = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }

}

void MainWindow::on_actionTemp_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionTemp->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionTemp->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for temp";

        this->curveComm.bit.temp = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);

    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle temp";
        this->curveComm.bit.temp = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }

}

void MainWindow::on_actionVol_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionVol->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionVol->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for voltage";

        this->curveComm.bit.vol = 1;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);

    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
        qDebug() << "cancle voltage";
        this->curveComm.bit.vol = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }

}
