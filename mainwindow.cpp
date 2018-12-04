#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rxDataDisplay->show();
    this->setGeometry(100,50,1100,600);

    this->menuBar()->hide();

    ui->sendButton->setIcon(QIcon("/home/pi/Pictures/heike1.jpg"));
    ui->sendButton->setIconSize(QSize(101, 30));

    ui->txDataInput->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    ui->rxDataDisplay->setStyleSheet("background-color: rgb(255, 255, 255, 10);");
    //ui->txDataInput->setTextColor(QColor("green"));
    ui->txDataInput->append("<font color=\"#00FF00\">绿色字体</font> ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    qDebug() << "paint event";
    p.drawPixmap(0,0,width(), height(), QPixmap("/home/pi/Pictures/heike2.jpg"));
}
