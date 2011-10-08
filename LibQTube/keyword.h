#ifndef KEYWORD_H
#define KEYWORD_H

#include <QObject>

class Keyword : public QObject
{
private:
    QString m_name;

public:
    Keyword(const QString& name);

    QString&    getName();
};

#endif // KEYWORD_H
