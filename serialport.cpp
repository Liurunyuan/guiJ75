#include "serialport.h"
#include "mainwindow.h"

Serialport::Serialport()
{

}

void Serialport::scanPort()
{
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        //ui->PortBox->addItem(serial.portName());

        this->setPort(info);
        if(this->open(QIODevice::ReadWrite))
        {
            qDebug() << this->portName();

            this->close();
        }
    }
}
