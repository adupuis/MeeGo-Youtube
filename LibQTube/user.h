#ifndef USER_H
#define USER_H

#include "retrievable.h"

class User : public Retrievable
{
public:
    // Constructor
    User(QString &name);

    void retrieve();
};

#endif // USER_H
