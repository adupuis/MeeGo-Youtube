#include "keyword.h"

Keyword::Keyword(QString& name) {
    m_name = name;
}

QString& Keyword::getName() {
    return m_name;
}
