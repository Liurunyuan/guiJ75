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
#include <QMutex>

//const  char packageHead[2] = {(char)0x5a, (char)0x5a};
//const  char packageTail[2] = {(char)0xa5, (char)0xa5};

class Serialport : public QSerialPort
{
    Q_OBJECT
public:
    Serialport();
    void scanPort();
    bool configPort(bool, QString);
    void sendStringEnquque(QByteArray);
    void sendData(QByteArray);
    int calCrc(int crc, const char* buf, int len);
    QByteArray getDisplayArray();
    QVector<QString> getAvailablePort();
    int isReadQEmpty();
    void clearReadQ();
    int getRxQLength();
    bool needUnpackData();
    void unpackData();
    
private slots:
    void readData();

private:
    QVector<QString> availablePort;
    QByteArray readComData;
    QQueue<QByteArray> readStringQ;
    QQueue<QByteArray> sendStringQ;
    QByteArray packageHead;
    QByteArray packageTail;
    QMutex mutex;
};

#endif // SERIALPORT_H
