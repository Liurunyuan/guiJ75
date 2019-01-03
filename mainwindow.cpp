#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWindow = this;
    ui->setupUi(this);
    this->setGeometry(100,50,1100,600);
    this->menuBar()->show();

//    task1 = new MyThread();
//    task1->start();

    initialUI();

    initTimer1();

    initTimer2();

    updateSerialInfo();

    this->curveCommand = 0;

    this->curveComm.all = 0;

    ui->dockWidget->setMinimumSize(150,300);
    ui->dockWidget->setWindowTitle("com port config");



    ui->dockWidget->setStyleSheet("QDockWidget {background-color:white;}");

    ui->systemconfig->setMinimumSize(150,300);
    ui->systemconfig->setStyleSheet("QDockWidget {background-color:red;"
                                    "color:red;"
                                    "border:2px outset white;"
                                    "}");
    //ui->systemconfig->setFeatures(QDockWidget::NoDockWidgetFeatures);

    ui->xComConfigDockWidget->setMinimumSize(150,300);
    ui->xComConfigDockWidget->setWindowTitle("com port config");
    ui->xComConfigDockWidget->setStyleSheet("QDockWidget {background-color:white;}");
    addDockWidget(Qt::LeftDockWidgetArea, ui->dockWidget);
    addDockWidget(Qt::LeftDockWidgetArea, ui->xComConfigDockWidget);

    ui->label->setStyleSheet("QLabel{color: red;}");
    ui->label_2->setStyleSheet("QLabel{color: red;}");
    ui->label_3->setStyleSheet("QLabel{color: red;}");
    ui->label_4->setStyleSheet("QLabel{color: red;}");
    ui->label_5->setStyleSheet("QLabel{color: red;}");

    ui->label_6->setStyleSheet("QLabel{color: white;}");
    ui->label_7->setStyleSheet("QLabel{color: white;}");
    ui->label_8->setStyleSheet("QLabel{color: white;}");
    ui->label_9->setStyleSheet("QLabel{color: white;}");
    ui->label_10->setStyleSheet("QLabel{color: white;}");

//    ui->label_5->setStyleSheet("QLabel{color: rgb(0,255,255);"
//                               "background-color: white;"
//                               "}");
}

MainWindow::~MainWindow()
{
    delete timer1;
    delete timer2;
    delete ui;
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
    ui->widget->yAxis->setRange(0,5);

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue));
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(0)->rescaleAxes();


    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::black));
    ui->widget->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(1)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(Qt::red));
    ui->widget->graph(2)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->widget->graph(2)->rescaleAxes();

    ui->widget->addGraph();
    ui->widget->graph(3)->setPen(QPen(Qt::yellow));
    ui->widget->graph(3)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(3)->rescaleAxes();

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

//    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
//    timeTicker->setTimeFormat("%h:%m:%s");
//    ui->widget->xAxis->setTicker(timeTicker);
    //customPlot->axisRect()->setupFullAxesBox();
    ui->widget->replot();
}

void MainWindow::initCustomPlot2()
{
    ui->widget2->show();
    //ui->widget->setBackground(QBrush(QColor(0, 0, 0, 20)));
    ui->widget2->legend->setVisible(true);
    ui->widget2->legend->setBrush(QColor(255,255,255,0));//legend背景色设为白色但背景透明，允许图像在legend区域可见

    //ui->widget->xAxis->setLabel("x");
    ui->widget2->xAxis->setRange(0,10);
    ui->widget2->xAxis->grid();


    //ui->widget->yAxis->setLabel("y");
    ui->widget2->yAxis->setRange(0,5);

    ui->widget2->addGraph();
    ui->widget2->graph(0)->setPen(QPen(Qt::blue));
    ui->widget2->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget2->graph(0)->rescaleAxes();


    ui->widget2->addGraph();
    ui->widget2->graph(1)->setPen(QPen(Qt::black));
    ui->widget2->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget2->graph(1)->rescaleAxes();

    ui->widget2->addGraph();
    ui->widget2->graph(2)->setPen(QPen(Qt::red));
    ui->widget2->graph(2)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget2->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->widget2->graph(2)->rescaleAxes();

    ui->widget2->addGraph();
    ui->widget2->graph(3)->setPen(QPen(Qt::yellow));
    ui->widget2->graph(3)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget2->graph(3)->rescaleAxes();

    ui->widget2->xAxis2->setVisible(true);
    ui->widget2->xAxis2->setTickLabels(false);
    ui->widget2->yAxis2->setVisible(true);
    ui->widget2->yAxis2->setTickLabels(false);



    ui->widget2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    connect(ui->widget2->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget2->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget2->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget2->yAxis2, SLOT(setRange(QCPRange)));

    //ui->widget->setFixedSize(1051,351);
    //ui->widget->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->widget2->xAxis2->setBasePen(QPen(Qt::white, 1));
    ui->widget2->yAxis2->setBasePen(QPen(Qt::white, 1));
    ui->widget2->xAxis2->setTickPen(QPen(Qt::white, 1));
    ui->widget2->yAxis2->setTickPen(QPen(Qt::white, 1));
    ui->widget2->xAxis2->setSubTickPen(QPen(Qt::white, 1));
    ui->widget2->yAxis2->setSubTickPen(QPen(Qt::white, 1));
    ui->widget2->xAxis2->setTickLabelColor(Qt::white);
    ui->widget2->yAxis2->setTickLabelColor(Qt::white);
    ui->widget2->xAxis2->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget2->yAxis2->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget2->xAxis2->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget2->yAxis2->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget2->xAxis2->grid()->setSubGridVisible(true);
    ui->widget2->yAxis2->grid()->setSubGridVisible(true);
    ui->widget2->xAxis2->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget2->yAxis2->grid()->setZeroLinePen(Qt::NoPen);
//    ui->widget->xAxis2->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->widget->yAxis2->setUpperEnding(QCPLineEnding::esSpikeArrow);


    ui->widget2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->widget2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->widget2->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->widget2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->widget2->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->widget2->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->widget2->xAxis->setTickLabelColor(Qt::white);
    ui->widget2->yAxis->setTickLabelColor(Qt::white);
    ui->widget2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->widget2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->widget2->xAxis->grid()->setSubGridVisible(true);
    ui->widget2->yAxis->grid()->setSubGridVisible(true);
    ui->widget2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->widget2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->widget2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
//    plotGradient.setColorAt(0, QColor(80, 80, 80));
//    plotGradient.setColorAt(1, QColor(50, 50, 50));
    plotGradient.setColorAt(0, QColor(100, 100, 100));
    plotGradient.setColorAt(1, QColor(112, 122, 225));
    ui->widget2->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->widget2->axisRect()->setBackground(axisRectGradient);

    ui->widget2->setWindowOpacity(0.8);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->widget2->xAxis->setTicker(timeTicker);
    //customPlot->axisRect()->setupFullAxesBox();
    ui->widget2->replot();
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

void MainWindow::unpack()
{
    this->serialPort->unpackData();
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
        ui->comBox_2->addItem(it);
    }
}

void MainWindow::initLcdNum()
{
    ui->lcdNumber->setDigitCount(25);
    // 设置显示的模式为十进制
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    // 设置显示外观
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    //ui->lcdNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber->setStyleSheet("background-color: rgb(255, 255, 255, 10);color: white;");
    ui->lcdNumber->show();
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
    timer2->setInterval(0);
    connect(timer2, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer2->start();
}

//void MainWindow::initTxDataDisplay()
//{
//    ui->txDataInput->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
//    ui->txDataInput->append("<font color=\"#00FF00\">绿色字体</font> ");
//}

//void MainWindow::initRxDataDisplay()
//{
//    ui->rxDataDisplay->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
//    ui->rxDataDisplay->show();
//}

void MainWindow::initialUI()
{
//    ui->sendButton->setIcon(QIcon("/home/pi/Pictures/heike1.jpg"));
//    ui->sendButton->setIconSize(QSize(101, 30));

//    initTxDataDisplay();

//    initRxDataDisplay();

    initLcdNum();

    initCustomPlot();
    initCustomPlot2();
}

void MainWindow::updatePlot()
{
    static int key = 0;
    static qint16 y = 0;
    int len;
    unsigned char yh;
    unsigned char yl;

    QByteArray tmp;
//    qDebug() << this->serialPort->getRxQLength();
//    while(this->serialPort->isReadQEmpty() != 1)
    if(this->serialPort->isReadQEmpty() != 1)
    {
        tmp = this->serialPort->getDisplayArray();
        len = tmp[2];
        for(int i = 0; i < len; ++i)
        {
            switch(tmp[3 + i * 3]){
            case 0:
                yh = tmp[4 + (i * 3)];
                yl = tmp[5 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(0)->addData(key,y);
                ui->widget->graph(0)->rescaleAxes(true);
                break;
            case 1:
                yh = tmp[4 + (i * 3)];
                yl = tmp[5 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(1)->addData(key,y);
                ui->widget->graph(1)->rescaleAxes(true);
                break;
            case 2:
                yh = tmp[4 + (i * 3)];
                yl = tmp[5 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(2)->addData(key,y);
                ui->widget->graph(2)->rescaleAxes(true);
                break;
            case 3:
                yh = tmp[4 + (i * 3)];
                yl = tmp[5 + (i * 3)];
                y = (qint16)((yh << 8) + yl);

                ui->widget->graph(3)->addData(key,y);

                ui->widget->graph(3)->rescaleAxes(true);
                break;
            default:
                break;
            }
        }

        ui->widget->xAxis->setRange(key, 160, Qt::AlignRight);
        ui->widget->replot();
        ++key;
    }
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(), height(), QPixmap("/home/pi/Pictures/heike2.jpg"));
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
    ui->lcdNumber->display(dateTime.toString("yyyy-MM-dd HH:mm:ss.zzz"));
}

MainWindow* MainWindow::mainWindow = NULL;

void MainWindow::on_openButton_clicked()
{
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

void MainWindow::on_openButton_2_clicked()
{
    if(ui->openButton_2->text() == "open")
    {
        if(serialPortX->configPort(true,ui->comBox_2->currentText()))
        {
           ui->openButton_2->setText("close");
        }
        else
        {

        }
    }
    else
    {
        if(serialPortX->configPort(false,ui->comBox_2->currentText()))
        {
           ui->openButton_2->setText("open");
        }
    }
}

void MainWindow::on_testbtn_clicked()
{

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

void MainWindow::on_actionDisplacement_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionDisplacement->isChecked() == true)
    {
        qDebug() << "ask for displacement";
        this->curveComm.bit.displacemet = 1;

        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);

        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
    }
    else
    {
        qDebug() << "cancle displacement";
        this->curveComm.bit.displacemet = 0;
        curve[7] = this->curveComm.half.low8;
        curve[6] = this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);

        qDebug() << send_data.toHex();

        this->serialPort->sendData(send_data);
    }
}

void MainWindow::on_actionMotor_speed_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_speed->isChecked() == true)
    {
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
    }
    else
    {
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
    }
}

void MainWindow::on_actionMotor_accel_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_accel->isChecked() == true)
    {
        qDebug() << "ask for motor accel";
        this->curveComm.bit.accel = 1;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
    }
    else
    {
        qDebug() << "cancle motor accel";
        this->curveComm.bit.accel = 0;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);
        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
    }
}

void MainWindow::on_actionCurrent_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionCurrent->isChecked() == true)
    {
        qDebug() << "ask for system current";

        this->curveComm.bit.current = 1;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);

    }
    else
    {
        qDebug() << "cancle system current";

        this->curveComm.bit.current = 0;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
    }
}

void MainWindow::on_actionBus_voltage_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionBus_voltage->isChecked() == true)
    {
        qDebug() << "ask for bus voltage";

        this->curveComm.bit.voltage = 1;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);

    }
    else
    {
        qDebug() << "cancle bus voltage";
        this->curveComm.bit.voltage = 0;
        curve[7] = (qint8)this->curveComm.half.low8;
        curve[6] = (qint8)this->curveComm.half.high8;

        crc = this->serialPort->calCrc(0, curve + 5, 3);

        curve[9] = (char)crc;
        curve[8] = (char)(crc >> 8);

        send_data.append(curve,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
    }
}



void MainWindow::on_SendBtn_clicked()
{
    //pack all the configuration data and send them to lower computer
    qDebug() << "send button clicked";
}
