#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sendButton = new QPushButton(this);
    sendButton->setText("send");
    sendButton->move(100,150);
    sendButton->show();
    ui->rxDataDisplay->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
