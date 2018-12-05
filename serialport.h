#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


class Serialport : public QSerialPort
{
public:
    Serialport();
    void scanPort();
};

#endif // SERIALPORT_H
