#ifndef USER_H
#define USER_H

class User : public Retrievable
{
public:
    // Constructor
    User(String &name);

    void retrieve();
};

#endif // USER_H
