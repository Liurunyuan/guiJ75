#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "singleton.h"
#include "observer.h"
#include "subject.h"
#include "client.h"
#include <QImageReader>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug() << "testing---------------";

    Singleton::GetInstance()->singlePrint();

    Subject *subject = new Subject();
    Client client(subject);

    subject->SetVal(5);
    subject->notify();
    subject->notify();
    subject->notify();

    //qDebug() << "main end";
    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();



    return a.exec();
}
