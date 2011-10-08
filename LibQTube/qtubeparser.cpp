#include "qtubeparser.h"
#include <QDateTime>
#include <iostream>
using namespace std;
QTubeParser::QTubeParser()
{
}
void QTubeParser::parseFeed(QIODevice *pIoDevice) {
    cout << "parseFeed... " <<endl;
    QDomDocument doc;
    QString error;
    int errorLine;
    int errorColumn;
    if(!doc.setContent(pIoDevice, true, &error, &errorLine, &errorColumn)) {
        cout << "!bad content at "<< errorLine << ":" << errorColumn << ": " << (error.toAscii().data()) <<endl;
        return;
    }
    QDomElement docElem = doc.documentElement();
    QDomNodeList itemElems = docElem.elementsByTagName("item");
    for(int i=0; i < itemElems.count(); i++) {
        QString *author = NULL;
        QString *title = NULL;
        QString *videoId = NULL;
        qreal rating = 0.0f;
        QDateTime * uploadedDate = NULL;
        qint32 duration = 0;

        QDomElement itemElem = itemElems.at(i).toElement();
        title = getSubElementText(itemElem, "title");
        author = getSubElementText(itemElem, "author");
        QDomNodeList mediaGroupElems = itemElem.elementsByTagName("group");
        if(!mediaGroupElems.isEmpty()) {
            QDomElement mediaGroupElem = mediaGroupElems.at(0).toElement();
            videoId = getSubElementText(mediaGroupElem, "videoid");
            QString *dateString = getSubElementText(mediaGroupElem, "uploaded");

            QDomNodeList durationElems = mediaGroupElem.elementsByTagName("duration");
            if(!durationElems.isEmpty()) {
                QDomElement durationElem = durationElems.at(0).toElement();
                QString durationString = durationElem.attribute("seconds");
                duration = durationString.toInt();
            }
        }
        QDomNodeList ratingElems = itemElem.elementsByTagName("rating");
        if(!ratingElems.isEmpty()) {
            QDomElement ratingElem = ratingElems.at(0).toElement();
            QString ratingString = ratingElem.attribute("average", "0.0");
            rating = (qreal) ratingString.toFloat();

        }
        if(title != NULL)
            cout << "video title: " << (title->toAscii().data()) << endl;

        if(author != NULL)
            cout << "  author: " << author->toAscii().data() << endl;

        if(videoId != NULL)
            cout << "  video id: " << videoId->toAscii().data() << endl;

        cout << "  rating: " << rating <<endl;
        cout << "  duration: " << duration << endl;
    }
}

QString* QTubeParser::getSubElementText(QDomElement pElement, QString pSubElementName) {
    QDomNodeList subElems = pElement.elementsByTagName(pSubElementName);
    for(int i=0; i < subElems.count(); i++) {
        QDomElement subElem = subElems.at(i).toElement();
        QString text = subElem.text();
        return new QString(text);
    }
    return new QString("");
}


