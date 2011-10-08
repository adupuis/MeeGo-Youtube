#ifndef QTUBEPARSER_H
#define QTUBEPARSER_H

#include <QDomDocument>

class QTubeParser
{
public:
    QTubeParser();
    void parseFeed(QIODevice *);
private:
    QString* getSubElementText(QDomElement pElement, QString pSubElementName);
};

#endif // QTUBEPARSER_H
