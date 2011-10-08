#ifndef RETRIEVABLE_H
#define RETRIEVABLE_H

#include <QObject>

class Retrievable : public QObject
{
public:
    virtual void retrieve() = 0;
};

#endif // RETRIEVABLE_H
