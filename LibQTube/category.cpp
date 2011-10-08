#include "category.h"

Category::Category(QString &name) {
    m_name = name;
}

QString& Category::getName() {
    return m_name;
}

void Category::retrieve() {
    // TODO
}
