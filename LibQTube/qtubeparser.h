#ifndef QTUBEPARSER_H
#define QTUBEPARSER_H

#include <QDomDocument>
#include <QList>
#include "video.h"

class QTubeParser
{
public:
    QTubeParser();
    QList<Video*> parseFeed(QIODevice &);
private:
    QString getSubElementText(QDomElement pElement, QString pSubElementName);
    Video* parseVideo(QDomElement pElement);
};

#endif // QTUBEPARSER_H
