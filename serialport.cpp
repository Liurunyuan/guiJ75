#include "serialport.h"
#include "mainwindow.h"

Serialport::Serialport()
{
    readComData.clear();


    packageHead.push_back(0x5a);
    packageHead.push_back(0x5a);
    packageTail.push_back(0xa5);
    packageTail.push_back(0xa5);

}

void Serialport::scanPort()
{
    qDebug() << "scan Port";
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {

        this->setPort(info);
        qDebug() << this->portName();
        if(this->open(QIODevice::ReadWrite))
        {
            availablePort.push_back(this->portName());
            qDebug() << "can be read and write";
            this->close();
        }
        qDebug() << "-------------------------------";
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
            QMessageBox::about(NULL, "提示", "串口已经被占用，请重新选择串口号！");
            qDebug() << "return false";
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

void Serialport::sendStringEnquque(QByteArray sdata)
{
    sendStringQ.enqueue(sdata);
}

void Serialport::readData()
{
//    qDebug() << "data is comming";
    QByteArray tmp = this->readAll();
    if(!tmp.isEmpty())
    {
        readComData.append(tmp);
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

int Serialport::getRxQLength()
{
    return readStringQ.length();
}

bool Serialport::needUnpackData()
{
    if(readComData.length() > 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Serialport::unpackData()
{
    int headpos = -1;
    int tailpos = -1;
    qDebug() << "unpacking the data";
    headpos = readComData.indexOf(packageHead);
    tailpos = readComData.indexOf(packageTail);
    qDebug() << readComData.toHex();
    while((headpos != -1) && (tailpos != -1))
    {
        qDebug() << "we find it";
        readStringQ.enqueue(readComData.left(tailpos + 1));
        qDebug() << readComData.left(tailpos + 1).toHex();
        readComData = readComData.right(readComData.length() - readComData.indexOf(packageTail)-2);
        headpos = readComData.indexOf(packageHead);
        tailpos = readComData.indexOf(packageTail);
    }
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
