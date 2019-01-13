#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWindow = this;
    ui->setupUi(this);
    ui->targetimage->installEventFilter(this);
    this->setGeometry(400, 100, 1295, 540);
    this->menuBar()->show();

    this->posX = 0;
    this->posY = 0;


    initialUI();

    initTimer1();

    initTimer2();

    updateSerialInfo();

    this->curveCommand = 0;
    this->curveComm.all = 0;
    this->curveComm2.all = 0;

    this->curveCount[0] = 0;
    this->curveCount[1] = 0;

    ui->tabWidget->setTabText(0, "俯仰通道");
    ui->tabWidget->setTabText(1, "横滚通道");

    configCuveMenu();

    ui->dockWidget->setMinimumSize(150,300);
    ui->dockWidget->setWindowTitle("俯仰串口设置");

    ui->dockWidget->setStyleSheet("QDockWidget {background-color:white;}");

    ui->systemconfig->setMinimumSize(150,300);
    ui->systemconfig->setStyleSheet("QDockWidget {background-color:red;"
                                    "color:red;"
                                    "border:2px outset white;"
                                    "}");
    //ui->systemconfig->setFeatures(QDockWidget::NoDockWidgetFeatures);
    ui->xComConfigDockWidget->setMinimumSize(150,300);
    ui->xComConfigDockWidget->setWindowTitle("横滚串口设置");
    ui->xComConfigDockWidget->setStyleSheet("QDockWidget {background-color:black;}");
    addDockWidget(Qt::LeftDockWidgetArea, ui->dockWidget);
    addDockWidget(Qt::LeftDockWidgetArea, ui->xComConfigDockWidget);
    ui->dockWidget->setStyleSheet("QDockWidget{color: black;}");
    ui->systemconfig->setStyleSheet("QDockWidget{color: black;}");
    QFont ft("Microsoft Yahei", 12, 75);
    ui->dockWidget->setFont(ft);
    ui->systemconfig->setFont(ft);
    ui->systemconfig->setWindowTitle("曲线显示/隐藏");
    ui->xComConfigDockWidget->setFont(ft);

    ui->label->setStyleSheet("QLabel{color: red;}");
    ui->label_2->setStyleSheet("QLabel{color: red;}");
    ui->label_3->setStyleSheet("QLabel{color: red;}");
    ui->label_4->setStyleSheet("QLabel{color: red;}");
    ui->label_5->setStyleSheet("QLabel{color: red;}");

    ui->label_6->setStyleSheet("QLabel{color: green;}");
    ui->label_7->setStyleSheet("QLabel{color: green;}");
    ui->label_8->setStyleSheet("QLabel{color: green;}");
    ui->label_9->setStyleSheet("QLabel{color: green;}");
    ui->label_10->setStyleSheet("QLabel{color: green;}");

//    ui->label_5->setStyleSheet("QLabel{color: rgb(0,255,255);"
//                               "background-color: white;"
//                               "}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:yellow;}");
//    ui->tableWidget->setFrameShape(QFrame::NoFrame);
//    ui->tableWidget->horizontalScrollBar()->setEnabled(false);
//    ui->tableWidget->verticalScrollBar()->setEnabled(false);

//    //设置代理
//    QLineEdit * m_edit = new QLineEdit;
//    //设置正则表达式限制输入,限制只能输入一到三位数字
//    QRegExp rx("^\\d\\d\\d\\d\\d?$");
//    m_edit->setValidator(new QRegExpValidator(rx,m_edit));
//    ui->tableWidget->setCellWidget(1,1,m_edit); //(0,0)项的item设置代理
//    QPixmap pixmap("/home/sean/Pictures/miaozhun.jpeg");

//    pixmap.scaled(QSize(10,10), Qt::KeepAspectRatio);
//    ui->targetimage->setPixmap(pixmap);
    ui->targetimage->setScaledContents(true);

    ui->targetimage->show();
}

MainWindow::~MainWindow()
{
    delete timer1;
    delete timer2;
    delete ui;
}
void MainWindow::configCuveMenu()
{
    ui->actionDisplacement->setChecked(false);
    ui->actionMotor_accel->setChecked(false);
    ui->actionMotor_speed->setChecked(false);
    ui->actionBus_voltage->setChecked(false);
    ui->actionCurrent->setChecked(false);
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
    QPainter painter(ui->targetimage);
    QImage image("/home/sean/Pictures/miaozhun.jpeg");
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

    painter.drawImage(target,image,source);
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
    initLcdNum();
    initCustomPlot();
    initCustomPlot2();
}

void MainWindow::updatePlot()
{
    static int key = 0;
    static int key2 = 0;
    static qint16 y = 0;
    int len;
    unsigned char yh;
    unsigned char yl;

    QByteArray tmp;
    if(this->serialPort->isReadQEmpty() != 1)
    {
        tmp = this->serialPort->getDisplayArray();
        len = tmp[2];
        for(int i = 0; i < len; ++i)
        {
            switch(tmp[5 + i * 3] % 4){
            case 0:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(0)->addData(key,y);
                ui->widget->graph(0)->rescaleAxes(true);
                break;
            case 1:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget->graph(1)->addData(key,y);
                ui->widget->graph(1)->rescaleAxes(true);
                break;
            case 2:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                this->posY = y;
                this->update();

                ui->widget->graph(2)->addData(key,y);
                ui->widget->graph(2)->rescaleAxes(true);
                break;
            case 3:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (qint16)((yh << 8) + yl);
                ui->widget->graph(3)->addData(key,y);
                ui->widget->graph(3)->rescaleAxes(true);
                break;
            default:
                break;
            }
        }
        ui->widget->xAxis->setRange(key, 260, Qt::AlignRight);
        ui->widget->replot();
        ++key;
    }
    else if(this->serialPortX->isReadQEmpty() != 1)
    {
        tmp = this->serialPortX->getDisplayArray();
        len = tmp[2];
        for(int i = 0; i < len; ++i)
        {
            switch(tmp[5 + i * 3]){
            case 0:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget2->graph(0)->addData(key2,y);
                ui->widget2->graph(0)->rescaleAxes(true);
                break;
            case 1:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                ui->widget2->graph(1)->addData(key2,y);
                ui->widget2->graph(1)->rescaleAxes(true);
                break;
            case 2:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (yh << 8) + yl;

                this->posX = y;
                this->update();

                ui->widget2->graph(2)->addData(key2,y);
                ui->widget2->graph(2)->rescaleAxes(true);
                break;
            case 3:
                yh = tmp[6 + (i * 3)];
                yl = tmp[7 + (i * 3)];
                y = (qint16)((yh << 8) + yl);

                ui->widget2->graph(3)->addData(key2,y);
                ui->widget2->graph(3)->rescaleAxes(true);
                break;
            default:
                break;
            }
        }

        ui->widget2->xAxis->setRange(key2, 160, Qt::AlignRight);
        ui->widget2->replot();
        ++key2;
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
    if(watched == ui->targetimage && event->type() == QEvent::Paint)
    {
        this->drawCurrentPosition(1,1);
    }
    return QWidget::eventFilter(watched,event);
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
        qDebug() << curveCount[0];
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionDisplacement->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
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
        this->serialPort->sendData(send_data);
    }
    else
    {
        --curveCount[0];
        if(curveCount[0] < 0)
        {
            curveCount[0] = 0;
        }
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
        this->serialPort->sendData(send_data);
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

void MainWindow::on_actionMotor_accel_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_accel->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionMotor_accel->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for motor accel";
        this->curveComm.bit.accel = 1;
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
        qDebug() << "cancle motor accel";
        this->curveComm.bit.accel = 0;
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

void MainWindow::on_actionCurrent_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionCurrent->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionCurrent->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for system current";

        this->curveComm.bit.current = 1;
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
        qDebug() << "cancle system current";

        this->curveComm.bit.current = 0;
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

void MainWindow::on_actionBus_voltage_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionBus_voltage->isChecked() == true)
    {
        if(curveCount[0] > MAXCURVE)
        {
            ui->actionBus_voltage->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[0]++;
        }
        qDebug() << "ask for bus voltage";

        this->curveComm.bit.voltage = 1;
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
        qDebug() << "cancle bus voltage";
        this->curveComm.bit.voltage = 0;
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
    QPen mpen;
    QPainter painter(this);
    //pack all the configuration data and send them to lower computer
    qDebug() << "send button clicked";
    QRect rect;
    rect = ui->targetimage->geometry();
    qDebug() << rect.width();
    qDebug() << rect.height();
    qDebug() << rect.center();
    this->update();
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    qint16 crc;
    QByteArray send_data;
    CurveStr value;
    int tmp;

    tmp = ui->tableWidget->item(row,column)->text().toInt();
    if(tmp > 32000 || tmp < -32000)
    {
        QMessageBox::about(NULL,"wrong value","The value range should be -32767 ~ 32767");
        ui->tableWidget->item(row,column)->setText("-99999999");

        return;
    }
    else
    {
        value.all = tmp;
    }
    configPara[5] = (char)(row + 6);
    configPara[7] = value.half.low8;
    configPara[6] = value.half.high8;
    if(column == 0)
    {
        crc = this->serialPort->calCrc(0, configPara + 5, 3);

        configPara[9] = (char)crc;
        configPara[8] = (char)(crc >> 8);

        send_data.append(configPara,12);
        qDebug() << send_data.toHex();
        this->serialPort->sendData(send_data);
        this->serialPort->sendData(send_data);
    }
    else if(column == 1)
    {
        crc = this->serialPortX->calCrc(0, configPara + 5, 3);

        configPara[9] = (char)crc;
        configPara[8] = (char)(crc >> 8);

        send_data.append(configPara,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}

void MainWindow::on_actionDisplacement2_triggered()
{
    qint16 crc;
    QByteArray send_data;

    if(ui->actionDisplacement2->isChecked() == true)
    {
        qDebug() << curveCount[1];
        if(curveCount[1] > MAXCURVE)
        {
            ui->actionDisplacement2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[1]++;
        }
        qDebug() << "ask for displacement2";
        this->curveComm2.bit.displacemet = 1;

        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);

        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
    else
    {
        --curveCount[1];
        if(curveCount[1] < 0)
        {
            curveCount[1] = 0;
        }
        qDebug() << "cancle displacement2";
        this->curveComm2.bit.displacemet = 0;
        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);

        qDebug() << send_data.toHex();

        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}

void MainWindow::on_actionMotor_speed2_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_speed2->isChecked() == true)
    {
        if(curveCount[1] > MAXCURVE)
        {
            ui->actionMotor_speed2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[1]++;
        }
        qDebug() << "ask for motor speed";
        this->curveComm2.bit.speed = 1;
        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
    else
    {
        --curveCount[1];
        if(curveCount[1] < 0)
        {
            curveCount[1] = 0;
        }
        qDebug() << "cancle motor speed";

        this->curveComm2.bit.speed = 0;

        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}

void MainWindow::on_actionMotor_accel2_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionMotor_accel2->isChecked() == true)
    {
        if(curveCount[1] > MAXCURVE)
        {
            ui->actionMotor_accel2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[1]++;
        }
        qDebug() << "ask for motor accel2";
        this->curveComm2.bit.accel = 1;
        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
    else
    {
        --curveCount[1];
        if(curveCount[1] < 0)
        {
            curveCount[1] = 0;
        }
        qDebug() << "cancle motor accel2";

        this->curveComm2.bit.accel = 0;

        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}

void MainWindow::on_actionCurrent2_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionCurrent2->isChecked() == true)
    {
        if(curveCount[1] > MAXCURVE)
        {
            ui->actionCurrent2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[1]++;
        }
        qDebug() << "ask for motor current2";
        this->curveComm2.bit.current = 1;
        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
    else
    {
        --curveCount[1];
        if(curveCount[1] < 0)
        {
            curveCount[1] = 0;
        }
        qDebug() << "cancle motor current2";

        this->curveComm2.bit.current = 0;

        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}

void MainWindow::on_actionBus_voltage2_triggered()
{
    qint16 crc;
    QByteArray send_data;
    if(ui->actionBus_voltage2->isChecked() == true)
    {
        if(curveCount[1] > MAXCURVE)
        {
            ui->actionBus_voltage2->setChecked(false);
            QMessageBox::about(NULL,"Warning","can not chooes more than 4 curves");
            return;
        }
        else
        {
            curveCount[1]++;
        }
        qDebug() << "ask for motor bus voltage2";
        this->curveComm2.bit.voltage = 1;
        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
    else
    {
        --curveCount[1];
        if(curveCount[1] < 0)
        {
            curveCount[1] = 0;
        }
        qDebug() << "cancle motor bus voltage2";

        this->curveComm2.bit.voltage = 0;

        curve2[7] = this->curveComm2.half.low8;
        curve2[6] = this->curveComm2.half.high8;

        crc = this->serialPortX->calCrc(0, curve2 + 5, 3);

        curve2[9] = (char)crc;
        curve2[8] = (char)(crc >> 8);

        send_data.append(curve2,12);
        qDebug() << send_data.toHex();
        this->serialPortX->sendData(send_data);
        this->serialPortX->sendData(send_data);
    }
}
