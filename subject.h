#ifndef SUBJECT_H
#define SUBJECT_H

#include <QDebug>
#include <vector>
#include <QVector>
#include "observer.h"

class Observer;
class Subject
{

public:
    Subject();
    Subject(int);
    ~Subject();
    void attach(Observer*);
    int GetVal();
    void SetVal(int val);
    void notify();
private:
    int value;
    std::vector<Observer*> mVector;
    QVector<int> mQVector;
};

#endif // SUBJECT_H
