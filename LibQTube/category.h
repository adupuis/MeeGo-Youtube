#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>

class Category : public QObject
{
private:
    static QList<Category*>   s_predefinedCategories;

    QString     m_name;
public:
    // Constructor
                Category(QString name);

    // Getters
    QString&    getName();

    void        requestVideos();

    static QList<Category*> getPredefinedCategories();
};

#endif // CATEGORY_H
