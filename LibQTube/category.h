#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>

#include "requestable.h"

class Category : public Requestable
{
private:
    static QList<Category*>   s_predefinedCategories;

    QString     m_name;
public:
    // Constructor
                Category(QString name);

    // Getters
    QString&    getName();

    void        request();

    static QList<Category*> getPredefinedCategories();
    static Category*        getPredefinedCategory(QString& name);
};

#endif // CATEGORY_H
