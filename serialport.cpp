#include "serialport.h"
#include "mainwindow.h"

Serialport::Serialport()
{
    readComData.clear();
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
    int headpos = -1;
    int tailpos = -1;
    QByteArray tmp = this->readAll();
    if(!tmp.isEmpty())
    {

        readComData.append(tmp);
        headpos = readComData.indexOf(packageHead);
        tailpos = readComData.indexOf(packageTail);
        if((headpos != -1) && (tailpos != -1))
        {
//            qDebug() << "length = " << readComData.length();
//            qDebug() << "head position =" << readComData.indexOf(packageHead);
//            qDebug() << "tail position =" << readComData.indexOf(packageTail);
//            qDebug() << readComData.toHex();

            //ui->textEditReceive->setText(byteArray.split('#').at(0));
            readStringQ.enqueue(readComData);
            readComData = readComData.right(readComData.length()-readComData.indexOf(packageTail)-2);
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

int Serialport::isReadQEmpty()
{
    return readStringQ.isEmpty();
}

int Serialport::calCrc(int crc, const char *buf, int len)
{
    int x;
    int i;

    for(i = 0; i < len; ++i)
    {
        x = ((crc >> 8) ^ buf[i]) & 0xff;
        x ^= x >> 4;
        crc = (crc << 8) ^ (x << 12) ^ (x << 5) ^ x;
        crc &= 0xffff;
    }
    return crc;
}
