#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
{
    while(1)
    {
        qDebug() << "mThread1";
        QThread::sleep(3);
    }
}
