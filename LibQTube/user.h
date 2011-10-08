#ifndef USER_H
#define USER_H

#include "retrievable.h"
#include "requestable.h"

class User : public Retrievable, Requestable
{
private:
    QString m_name;

public:
    // Constructor
    User(QString &name);

    QString& getName();

    void retrieve();
    void request();
};

#endif // USER_H
