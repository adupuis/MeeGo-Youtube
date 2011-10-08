#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>

class Category : public QObject
{
private:
    QString name;
public:
    // Constructor
                Category(QString &name);

    // Getters
    QString&    getName();
};

#endif // CATEGORY_H
