#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void MainWindow::updateSerialInfo()
{
    serialPort = new Serialport();
    serialPort->scanPort();

    for(auto it : serialPort->getAvailablePort())
    {
        ui->comBox->addItem(it);
    }
}

void MainWindow::initialUI()
{
//    ui->sendButton->setIcon(QIcon("/home/pi/Pictures/heike1.jpg"));
//    ui->sendButton->setIconSize(QSize(101, 30));

    ui->txDataInput->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->rxDataDisplay->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    //ui->txDataInput->setTextColor(QColor("green"));
    ui->txDataInput->append("<font color=\"#00FF00\">绿色字体</font> ");


    ui->lcdNumber->show();

    timer1 = new QTimer(this);
    timer1->setInterval(1000);
    connect(timer1, SIGNAL(timeout()), this, SLOT(refreshLCD()));
    timer1->start();

    timer2 = new QTimer(this);
    timer2->setInterval(10);
    connect(timer2, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer2->start();

    // 设置能显示的位数
    ui->lcdNumber->setDigitCount(25);
    // 设置显示的模式为十进制
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    // 设置显示外观
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    //ui->lcdNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber->setStyleSheet("background-color: rgb(255, 255, 255, 10);color: white;");
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
    y = tmp[12];

    qDebug() << "on test button clicked";
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->rescaleAxes(true);
    ui->widget->xAxis->setRange(x, 8, Qt::AlignRight);
    ui->widget->replot();
    ++x;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rxDataDisplay->show();
    this->setGeometry(100,50,1100,600);

    this->menuBar()->hide();

    initialUI();

    QVector<double> x(101),y(101);
                //图形为y=x^3
    for(int i=0;i<101;i++)
    {
        //x[i] = i/5.0-10;
        //y[i] = x[i]*x[i]*x[i];//qPow(x[i],3)
        x[i] = i;
        y[i] = x[i];
    }

    //ui->widget->setBackground(QBrush(Qt::black));
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
    //ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    //ui->widget->graph(0)->setName("曲线");
    //ui->widget->graph(0)->setData(x,y);


    updateSerialInfo();

    task1 = new MyThread();
    task1->start();
//    mThread1 = new QThread(this);
//    //this->moveToThread(mThread1);

//    connect(mThread1, SIGNAL(started()),this,SLOT(display()));
//    mThread1->start();
}

MainWindow::~MainWindow()
{
    delete timer1;
    delete timer2;
    delete ui;
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
void MainWindow::testPrint()
{
    qDebug() << "test print";
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
    static int x = 0;
    static int y = 0;
    QByteArray tmp;
    if(this->serialPort->isReadQEmpty())
    {
        return;
    }
    tmp = this->serialPort->getDisplayArray();
    qDebug() << tmp.toHex();
    y = tmp[12];

    qDebug() << "on test button clicked";
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->rescaleAxes(true);
    ui->widget->xAxis->setRange(x, 8, Qt::AlignRight);
    ui->widget->replot();
    ++x;
    //++y;
}

void MainWindow::display()
{
    while(1){
        qDebug() << "mThread1";
        QThread::sleep(3);
    }
}
