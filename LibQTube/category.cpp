#include "category.h"

QList<Category*>   Category::s_predefinedCategories;

Category::Category(QString name) {
    m_name = name;
}

QString& Category::getName() {
    return m_name;
}

void Category::request() {
    // TODO with TubeRequester
}

QList<Category*> Category::getPredefinedCategories() {
    if (s_predefinedCategories.empty()) {
        s_predefinedCategories.append(new Category(QString("Autos")));
        s_predefinedCategories.append(new Category(QString("Comedy")));
        s_predefinedCategories.append(new Category(QString("Education")));
        s_predefinedCategories.append(new Category(QString("Entertainment")));
        s_predefinedCategories.append(new Category(QString("Film")));
        s_predefinedCategories.append(new Category(QString("Howto")));
        s_predefinedCategories.append(new Category(QString("Music")));
        s_predefinedCategories.append(new Category(QString("News")));
        s_predefinedCategories.append(new Category(QString("People")));
        s_predefinedCategories.append(new Category(QString("Animals")));
        s_predefinedCategories.append(new Category(QString("Tech")));
        s_predefinedCategories.append(new Category(QString("Sports")));
        s_predefinedCategories.append(new Category(QString("Travel")));
    }

    return s_predefinedCategories;
}

Category* Category::getPredefinedCategory(QString &name) {
    QList<Category*> categories = Category::getPredefinedCategories();
    QListIterator<Category*> i(categories);
    while (i.hasNext()) {
        Category* c = i.next();
        if (c->getName().compare(name) == 0) {
            return c;
        }
    }
    return NULL;
}
