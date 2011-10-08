#include "category.h"

Category::Category(QString name) {
    m_name = name;
}

QString& Category::getName() {
    return m_name;
}

void Category::requestVideos() {
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
