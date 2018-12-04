#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

class Subject;
class Observer
{
public:
    Observer(Subject* sub);
    ~Observer();

    virtual void update() = 0;

private:
    Subject* subj;
    int tmp;
};

#endif // OBSERVER_H
