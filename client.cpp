#include "client.h"
#include <QDebug>

Client::Client(Subject *sub) :Observer(sub)
{

}

Client::~Client()
{

}

void Client::update()
{
    qDebug() << "client update";

}
