#ifndef CATEGORY_H
#define CATEGORY_H

#include "retrievable.h"

class Category : public QObject
{
private:
    QString m_name;
public:
    // Constructor
                Category(QString &name);

    // Getters
    QString&    getName();

    void        retrieve();
};

#endif // CATEGORY_H
