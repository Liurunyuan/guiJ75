#include "subject.h"

Subject::Subject()
{
    qDebug() << "subject construct";
}

Subject::~Subject()
{
    qDebug() << "subject destruct";
}

void Subject::SetVal(int val)
{
    value = val;
}

int Subject::GetVal()
{
    return value;
}

void Subject::notify()
{

    for(auto it : mVector)
    {
        it->update();

    }

}

void Subject::attach(Observer *obj)
{
    mVector.push_back(obj);
}
