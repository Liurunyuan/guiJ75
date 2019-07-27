#include "ota.h"
char ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
    return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
    return ch-'a'+10;
    else return (-1);
}

QByteArray QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
    hstr=str[i].toLatin1();
    if(hstr == ' ')
    {
    i++;
    continue;
    }
    i++;
    if(i >= len)
    break;
    lstr = str[i].toLatin1();
    hexdata = ConvertHexChar(hstr);
    lowhexdata = ConvertHexChar(lstr);
    if((hexdata == 16) || (lowhexdata == 16))
    break;
    else
    hexdata = hexdata*16+lowhexdata;
    i++;
    senddata[hexdatalen] = (char)hexdata;
    hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;

}


ota::ota(MainWindow* main)
{
    mainPlot = main;
}
ota::~ota()
{
    this->requestInterruption();
    this->quit();
    this->wait();
}

void ota::run()
{
    int count = 0;
    int totalline = 0;
    QByteArray laji;

    while(!isInterruptionRequested())
    {
        QThread::msleep(2000);
//        if(MainWindow::getInstance()->getOtaStatus() == 1){
        if(MainWindow::getInstance()->getOtaWaitingCmd() == 1){
            QFile file2(MainWindow::getInstance()->getFile2());

            if(file2.open(QIODevice::ReadOnly)){
                while(!file2.atEnd()){
                   file2.readLine();
                   ++totalline;
                }
                file2.close();
                qDebug() << "total line number = " << totalline;
            }

            if(file2.open(QIODevice::ReadOnly)){
                while(!file2.atEnd()){
                   QThread::msleep(300);


                   QByteArray t = file2.readLine();
                   QByteArray m = t.left(t.length() - 2);
                    m = m.right(m.length() - 1);

                   QString s = m.data();

                   m = QString2Hex(s);

                   m.insert(0,':');

                   count ++;
                   qDebug() << count;
                   MainWindow::getInstance()->setOtaPercentage(count/(double)totalline);

                   MainWindow::getInstance()->otaFlashDataEnqueue(m);
                }
//                MainWindow::getInstance()->setOtaStatus(0);
                MainWindow::getInstance()->setOtaWaitingCmd(0);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                laji.append(0x55);
                 MainWindow::getInstance()->otaFlashDataEnqueue(laji);

                 count = 0;

                qDebug()<<"UI--------------------OTA end";
                file2.close();
             }
        }
    }
}

QByteArray ota::hexStringtoByteArray(QString hex)
{
    QByteArray ret;

    return ret;
}




