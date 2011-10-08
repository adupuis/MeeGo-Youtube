#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>

class Category : public QObject
{
private:
    QString m_name;
public:
    // Constructor
                Category(QString &name);

    // Getters
    QString&    getName();

    void        requestVideos();
};

#endif // CATEGORY_H
