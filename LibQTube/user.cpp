#include "user.h"

User::User(QString &name) {
    m_name = name;
}

QString& User::getName() {
    return m_name;
}

void retrieve() {
    // TODO
}
