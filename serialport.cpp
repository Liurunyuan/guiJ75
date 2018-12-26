#include "serialport.h"
#include "mainwindow.h"

Serialport::Serialport()
{
    readComData.clear();
    tail.push_back(0xa5);
    tail.push_back(0xa5);


    //readStringQ.clear();
}

void Serialport::scanPort()
{
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {

        this->setPort(info);
        if(this->open(QIODevice::ReadWrite))
        {
            qDebug() << this->portName();
            availablePort.push_back(this->portName());

            this->close();
        }
    }
}

bool Serialport::configPort(bool isOpen, QString portName)
{
    if(isOpen)
    {
        this->setPortName(portName);
        if(this->open(QIODevice::ReadWrite))
        {
            this->setBaudRate(QSerialPort::Baud115200);
                       //设置数据位
            this->setDataBits(QSerialPort::Data8);
                       //设置校验位
            this->setParity(QSerialPort::NoParity);
                       //设置流控制
            this->setFlowControl(QSerialPort::NoFlowControl);
                       //设置停止位
            this->setStopBits(QSerialPort::OneStop);
            QMessageBox::about(NULL, "提示", "串口打开！");
            connect(this, SIGNAL(readyRead()), this, SLOT(readData()));
            return true;
        }
        else
        {
            QMessageBox::about(NULL, "提示", "串口没有打开！");
            return false;
        }
    }
    else
    {
        this->close();
        QMessageBox::about(NULL, "提示", "串口closed！");
        return true;
    }
}

void Serialport::readData()
{
    QByteArray tmp = this->readAll();
    if(!tmp.isEmpty())
    {
        readStringQ.enqueue(tmp);
        readComData.append(tmp);
        if(readComData.contains(tail))
        {

            qDebug() << "we find the tail of data strcture";
            //ui->textEditReceive->setText(byteArray.split('#').at(0));
            //readComData = readComData.right(readComData.length()-readComData.indexOf(tail)-1);
        }
    }
}

void Serialport::sendData(QByteArray data)
{
    this->write(data);
}

QByteArray Serialport::getDisplayArray()
{
    return readStringQ.dequeue();
}

QVector<QString> Serialport::getAvailablePort()
{
    return availablePort;
}
