#include "singleton.h"
#include <QDebug>

Singleton* Singleton::mSingle = NULL;
Singleton::Singleton()
{

}

Singleton* Singleton::GetInstance()
{
    {
        qDebug() << "singleton class get instance";
        if(mSingle == NULL)
        {
            mSingle = new Singleton();
        }
        return mSingle;
    }
}

void Singleton::singlePrint()
{
    qDebug() << "singlePrint";
}



