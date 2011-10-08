#include "keyword.h"

Keyword::Keyword(const QString& name) {
    m_name = name;
}

QString& Keyword::getName() {
    return m_name;
}
