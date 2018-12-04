#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>


class Serialport : public QSerialPort
{
public:
    Serialport();
};

#endif // SERIALPORT_H
