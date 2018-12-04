#include "observer.h"

Observer::Observer(Subject *sub)
{
    subj = sub;
    subj->attach(this);
}

Observer::~Observer()
{

}

