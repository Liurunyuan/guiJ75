#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,50,1100,600);
    this->menuBar()->hide();

    task1 = new MyThread();
    task1->start();

    initialUI();

    initTimer1();

    initTimer2();

    updateSerialInfo();


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
    //ui->widget->legend->setVisible(true);
    //ui->widget->xAxis->setLabel("x");
    ui->widget->xAxis->setRange(0,10);

    //ui->widget->yAxis->setLabel("y");
    ui->widget->yAxis->setRange(0,10);
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue));
    ui->widget->xAxis->grid();
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(false);

    ui->widget->graph(0)->rescaleAxes();

    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    ui->widget->setFixedSize(550,400);
    ui->widget->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
}
void MainWindow::updateSerialInfo()
{
    serialPort = new Serialport();
    serialPort->scanPort();

    for(auto it : serialPort->getAvailablePort())
    {
        ui->comBox->addItem(it);
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
    timer2->setInterval(10);
    connect(timer2, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer2->start();
}

void MainWindow::initTxDataDisplay()
{
    ui->txDataInput->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->txDataInput->append("<font color=\"#00FF00\">绿色字体</font> ");
}

void MainWindow::initRxDataDisplay()
{
    ui->rxDataDisplay->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->rxDataDisplay->show();
}

void MainWindow::initialUI()
{
//    ui->sendButton->setIcon(QIcon("/home/pi/Pictures/heike1.jpg"));
//    ui->sendButton->setIconSize(QSize(101, 30));

    initTxDataDisplay();

    initRxDataDisplay();

    initLcdNum();

    initCustomPlot();
}

void MainWindow::updatePlot()
{
    static int x = 0;
    static int y = 0;
    QByteArray tmp;
    if(this->serialPort->isReadQEmpty())
    {
        return;
    }
    tmp = this->serialPort->getDisplayArray();
    qDebug() << tmp.toHex();

    int len = 0;
    len = tmp[2];
    for(int i = 0; i < len; ++i)
    {
        //TODO need to fix later
    }
    y = tmp[12];

    qDebug() << "on test button clicked";
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->rescaleAxes(true);
    ui->widget->xAxis->setRange(x, 8, Qt::AlignRight);
    ui->widget->replot();
    ++x;
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
        if(serialPort->configPort(true,ui->comBox->currentText()));
        {
           ui->openButton->setText("close");
        }
    }
    else
    {
        if(serialPort->configPort(false,ui->comBox->currentText()));
        {
           ui->openButton->setText("open");
        }
    }
}

void MainWindow::on_testbtn_clicked()
{

}
