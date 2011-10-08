#ifndef KEYWORD_H
#define KEYWORD_H

#include <QObject>

#include "requestable.h"

class Keyword : public Requestable
{
private:
    QString m_name;

public:
    Keyword(const QString& name);

    QString&    getName();

    void        request();
};

#endif // KEYWORD_H
