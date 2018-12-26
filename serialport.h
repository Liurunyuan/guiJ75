#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QQueue>
#include <QString>
#include <QByteArray>


class Serialport : public QSerialPort
{
public:
    Serialport();
    void scanPort();
    bool configPort(bool, QString);
    void readData();
    void sendData(QByteArray);
    QByteArray getDisplayArray();
    QVector<QString> getAvailablePort();

private:
    QVector<QString> availablePort;
    QByteArray readComData;
    QByteArray tail;
    QQueue<QByteArray> readStringQ;
};

#endif // SERIALPORT_H
