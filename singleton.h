#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    Singleton();
    static Singleton* GetInstance();

    void singlePrint();
private:
    static Singleton *mSingle;
};

#endif // SINGLETON_H
