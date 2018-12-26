#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtCore/QObject>
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
    Q_OBJECT
public:
    Serialport();
    void scanPort();
    bool configPort(bool, QString);

    void sendData(QByteArray);
    int calCrc(int crc, const char* buf, int len);
    QByteArray getDisplayArray();
    QVector<QString> getAvailablePort();
private slots:
    void readData();

private:
    QVector<QString> availablePort;
    QByteArray readComData;
    QByteArray tail;
    QQueue<QByteArray> readStringQ;
};

#endif // SERIALPORT_H
