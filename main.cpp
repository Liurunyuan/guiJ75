#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "singleton.h"
#include "observer.h"
#include "subject.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "test";

    Singleton::GetInstance()->singlePrint();

    Subject *subject = new Subject();
    Client client(subject);

    subject->SetVal(5);
    subject->notify();
    subject->notify();
    subject->notify();

    qDebug() << "main end";


    return a.exec();
}
