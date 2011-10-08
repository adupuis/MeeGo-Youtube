#ifndef QTUBEPARSER_H
#define QTUBEPARSER_H

#include <QDomDocument>
#include "video.h"

class QTubeParser
{
public:
    QTubeParser();
    void parseFeed(QIODevice &);
private:
    QString getSubElementText(QDomElement pElement, QString pSubElementName);
    Video* parseVideo(QDomElement pElement);
};

#endif // QTUBEPARSER_H
