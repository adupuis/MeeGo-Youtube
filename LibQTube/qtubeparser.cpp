#include "qtubeparser.h"
#include <QDateTime>
#include <iostream>
#include "user.h"

using namespace std;
QTubeParser::QTubeParser()
{
}
QList<Video*> QTubeParser::parseFeed(QIODevice &pIoDevice) {
    QList<Video*> result;
    QDomDocument doc;
    QString error;
    int errorLine;
    int errorColumn;
    if(!doc.setContent(&pIoDevice, true, &error, &errorLine, &errorColumn)) {
        cout << "!bad content at "<< errorLine << ":" << errorColumn << ": " << (error.toAscii().data()) <<endl;
        return result;
    }
    QDomElement docElem = doc.documentElement();
    QDomNodeList itemElems = docElem.elementsByTagName("item");
    for(int i=0; i < itemElems.count(); i++) {

        QDomElement itemElem = itemElems.at(i).toElement();
        Video *video = parseVideo(itemElem);
        result.append(video);
    }
    return result;
}

QString QTubeParser::getSubElementText(QDomElement pElement, QString pSubElementName) {
    QDomNodeList subElems = pElement.elementsByTagName(pSubElementName);
    for(int i=0; i < subElems.count(); i++) {
        QDomElement subElem = subElems.at(i).toElement();
        QString text = subElem.text();
        return text;
    }
    QString empty("");
    return empty;
}

Video *QTubeParser::parseVideo(QDomElement pElement) {
    QString author;
    QString title;
    QString videoId;
    qreal rating = 0.0f;
    qint32 duration = 0;
    QString uploadedDate;
    QString description;
    qint32 favoriteCount = 0;
    qint32 viewCount = 0;
    Category *category = NULL;

    title = getSubElementText(pElement, "title");
    author = getSubElementText(pElement, "author");
    QDomNodeList mediaGroupElems = pElement.elementsByTagName("group");
    if(!mediaGroupElems.isEmpty()) {
        QDomElement mediaGroupElem = mediaGroupElems.at(0).toElement();
        videoId = getSubElementText(mediaGroupElem, "videoid");
        uploadedDate = getSubElementText(mediaGroupElem, "uploaded");
        description = getSubElementText(mediaGroupElem, "description");
        QString categoryString = getSubElementText(mediaGroupElem, "category");
        category = new Category(categoryString);

        QDomNodeList durationElems = mediaGroupElem.elementsByTagName("duration");
        if(!durationElems.isEmpty()) {
            QDomElement durationElem = durationElems.at(0).toElement();
            QString durationString = durationElem.attribute("seconds");
            duration = durationString.toInt();
        }

    }
    QDomNodeList ratingElems = pElement.elementsByTagName("rating");
    if(!ratingElems.isEmpty()) {
        QDomElement ratingElem = ratingElems.at(0).toElement();
        QString ratingString = ratingElem.attribute("average", "0.0");
        rating = (qreal) ratingString.toFloat();

    }
    QDomNodeList statisticsElems = pElement.elementsByTagName("statistics");
    if(!statisticsElems.isEmpty()) {
        QDomElement statisticsElem = statisticsElems.at(0).toElement();
        QString favoriteCountStr = statisticsElem.attribute("favoriteCount");
        favoriteCount = favoriteCountStr.toInt();
        QString viewCountStr = statisticsElem.attribute("viewCount");
        viewCount = viewCountStr.toInt();
    }
    Video * result = new Video(videoId);
    User *user = new User(author);
    result->setAuthor(user);
    result->setName(title);
    result->setDescription(description);
    result->setCategory(category);
    result->setDuration(duration);
    result->setRating(rating);
    result->setPubDate(uploadedDate);
    result->setFavoriteCount(favoriteCount);
    result->setViewCount(viewCount);

    return result;
}

