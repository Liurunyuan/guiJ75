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
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {

        this->setPort(info);
        if(this->open(QIODevice::ReadWrite))
        {
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

int Serialport::clearReadQ(){
    readStringQ.clear();
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
    int length = 0;
    QByteArray key;
    headpos = readComData.indexOf(packageHead);
    while(headpos != -1)
    {
        if((readComData.length() - headpos) > 10)
        {
            length = readComData[headpos + 2] * 3 + 9;
            if(length < 12)
            {
                readComData = readComData.right(readComData.length() - length - headpos);
                return;
            }
            if(length <= (readComData.length() - headpos))
            {
                if(readComData[headpos + length - 1] == (char)0xa5)
                {
                    if(readComData[headpos + length - 2] == (char)0xa5)
                    {
                        key = readComData.mid(headpos, length);
                        readStringQ.enqueue(key);
                        readComData = readComData.right(readComData.length() - length - headpos);
                        headpos = readComData.indexOf(packageHead);
                    }
                    else
                    {
                        readComData = readComData.right(readComData.length() - 1);
                        return;
                    }
                }
                else
                {
                    readComData = readComData.right(readComData.length() - 1);
                    return;
                }
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
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
