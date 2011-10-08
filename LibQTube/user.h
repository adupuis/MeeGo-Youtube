#ifndef USER_H
#define USER_H

#include "retrievable.h"

class User : public Retrievable
{
private:
    QString m_name;

public:
    // Constructor
    User(QString &name);

    void retrieve();
};

#endif // USER_H
