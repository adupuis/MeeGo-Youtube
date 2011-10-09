#include "qtubeparser.h"
#include <QDateTime>
#include <QStringList>
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
    // Read the XML file and check for errors.
    if(!doc.setContent(&pIoDevice, true, &error, &errorLine, &errorColumn)) {
        cout << "!bad content at "<< errorLine << ":" << errorColumn << ": " << (error.toAscii().data()) <<endl;
        return result;
    }
    QDomElement docElem = doc.documentElement();

    // Iterate through all the item elements (each item element = one video).
    QDomNodeList itemElems = docElem.elementsByTagName("item");
    for(int i=0; i < itemElems.count(); i++) {

        QDomElement itemElem = itemElems.at(i).toElement();
        Video *video = parseVideo(itemElem);
        result.append(video);
    }
    return result;
}

/**
 * XML utility method: Return the content (CDATA) of the first child
 * element with the given tag name.
 */
QString QTubeParser::getSubElementText(QDomElement pElement, QString pSubElementName) {
    QDomNodeList subElems = pElement.elementsByTagName(pSubElementName);
    // If no child elem exists with the given tag, just return an empty string
    if(subElems.isEmpty()) {
        return "";
    }
    QDomElement subElem = subElems.at(0).toElement();
    QString text = subElem.text();
    return text;
}

qint32 QTubeParser::getIntAttribute(QDomElement pElement, QString pAttributeName) {
    QString valueString = pElement.attribute(pAttributeName, "0");
    qint32 value = valueString.toInt();
    return value;
}

/**
 * Parse the XML element for a given video and create a Video object for the video.
 */
Video *QTubeParser::parseVideo(QDomElement pElement) {
    // Video attributes
    QString author;
    QString title;
    QString videoId;
    qreal rating = 0.0f;
    qint32 duration = 0;
    QString uploadedDate;
    QString description;
    qint32 favoriteCount = 0;
    qint32 viewCount = 0;
    qint32 numLikes = 0;
    qint32 numDislikes = 0;
    Category *category = NULL;
    QStringList keywordsList;
    // Video attributes in the top element for this video.
    title = getSubElementText(pElement, "title");
    author = getSubElementText(pElement, "author");

    // Look for video attributes in the media:group element.
    QDomNodeList mediaGroupElems = pElement.elementsByTagName("group");
    if(!mediaGroupElems.isEmpty()) {
        // Assume there's only one media:group element for the video.
        QDomElement mediaGroupElem = mediaGroupElems.at(0).toElement();

        // Get the media:group level attributes.
        // Example:
        // <media:category label='Music'>Music</media:category>
        // <media:description type='plain'>My cool video</media:description>
        // <yt:uploaded>2011-10-06T23:13:59.000Z</yt:uploaded>
        // <yt:videoid>lbvzkdYqJDc</yt:videoid>

        videoId = getSubElementText(mediaGroupElem, "videoid");
        uploadedDate = getSubElementText(mediaGroupElem, "uploaded");
        description = getSubElementText(mediaGroupElem, "description");

        // TODO we should have a separate class manage the list of possible
        // categories, instead of allocating a new Category object for each user.
        QString categoryString = getSubElementText(mediaGroupElem, "category");
        category = Category::getPredefinedCategory(categoryString);
        if(category == NULL)
            cerr << "Category not predefined: " << categoryString.toAscii().data() << endl;

        // Duration of the video. Ex: <yt:duration seconds="211"/>
        QDomNodeList durationElems = mediaGroupElem.elementsByTagName("duration");
        if(!durationElems.isEmpty()) {
            QDomElement durationElem = durationElems.at(0).toElement();
            duration = getIntAttribute(durationElem, "seconds");
        }

        // Keywords.  Example: <media:keywords>chopin, melancholy, cello</media:keywords>
        QString keywordsListString = getSubElementText(mediaGroupElem, "keywords");
        keywordsList = keywordsListString.split(",",QString::SkipEmptyParts);
    }
    // There are two rating elements for 1-5 ratings, and for like/dislike ratings.
    QDomNodeList ratingElems = pElement.elementsByTagName("rating");
    for(int i=0; i < ratingElems.count(); i++) {
        QDomElement ratingElem = ratingElems.at(i).toElement();
        // Example:
        // <gd:rating average='4.8575497' max='5' min='1' numRaters='2808'/>
        if(ratingElem.prefix() == "gd") {
            QString ratingString = ratingElem.attribute("average", "0.0");
            rating = (qreal) ratingString.toFloat();
        }
        // Example:
        // <yt:rating numDislikes='100' numLikes='2708'/>
        else if(ratingElem.prefix() == "yt") {
            numLikes = getIntAttribute(ratingElem, "numLikes");
            numDislikes = getIntAttribute(ratingElem, "numDislikes");
        }
    }

    // Get view statistics. Example:
    // <yt:statistics favoriteCount='1888' viewCount='216149'/>
    QDomNodeList statisticsElems = pElement.elementsByTagName("statistics");
    if(!statisticsElems.isEmpty()) {
        QDomElement statisticsElem = statisticsElems.at(0).toElement();
        favoriteCount = getIntAttribute(statisticsElem, "favoriteCount");
        viewCount = getIntAttribute(statisticsElem, "viewCount");
    }

    // Now create the video and set the attributes.
    Video *result = new Video(videoId);

    // TODO we probably shouldn't create a new user here, but have some
    // separate class which handles the users.  Otherwise we may allocate
    // a User object multiple times for the same user.
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
    result->setLikes(numLikes);
    result->setDislikes(numDislikes);

    for(int i=0; i < keywordsList.count(); i++) {
        // TODO need new class to manage list of keywords?
        result->addKeyword(new Keyword(keywordsList.at(i)));
    }

    return result;
}
