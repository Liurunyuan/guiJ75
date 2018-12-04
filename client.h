#ifndef CLIENT_H
#define CLIENT_H

#include "observer.h"


class Client:public Observer
{
public:
    Client(Subject*);
    ~Client();
    void update();
private:

};

#endif // CLIENT_H
