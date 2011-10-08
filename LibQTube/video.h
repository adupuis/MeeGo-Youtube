#ifndef VIDEO_H
#define VIDEO_H

#include <QDateTime>

#include "user.h"
#include "category.h"

class Video : public QObject {
private:
    static const QString    BASE_THUMBNAIL_URL;
    static const QString    THUMBNAIL_FILE;
    static const QString    HQ_THUMBNAIL_FILE;
    static const QString    BASE_BROWSER_URL;

private:
    Category*   m_category;
    User*       m_author;

    QString     m_name;
    QString     m_id;             // Only the string after http://www.youtube.com/watch?v=
    QDateTime   m_pubDate;
    QString     m_description;
    qint32      m_duration;

    qint32      m_favoriteCount;
    qint32      m_viewCount;
    qint32      m_dislikes;
    qint32      m_likes;
    qreal       m_rating;
    qint32      m_numRating;

public:
    // Constructor
                Video       (QString &id);
                Video       (QString &id, Category *category, User *author);

    // Getters
    Category*   getCategory();
    User*       getAuthor();
    QString&    getName();
    QString&    getId();
    QDateTime&  getPubDate();
    QString&    getDescription();
    qint32      getDuration();
    qint32      getFavoriteCount();
    qint32      getViewCount();
    qint32      getDislikes();
    qint32      getLikes();
    qreal       getRating();
    qint32      getNumRating();

    // Setters
    void        setCategory     (Category *category);
    void        setAuthor       (User *author);
    void        setName         (QString &name);
    void        setPubDate      (QDateTime &date);
    void        setPubDate      (QString &date);
    void        setDescription  (QString &description);
    void        setDuration     (qint32 duration);
    void        setFavoriteCount(qint32 count);
    void        setViewCount    (qint32 count);
    void        setDislikes     (qint32 count);
    void        setLikes        (qint32 count);
    void        setRating       (qreal rating);
    void        setNumRating    (qint32 count);

    // URL generated from id
    QString     getThumbnailUrl();
    QString     getHqThumbnailUrl();
    QString     getBrowserUrl();
};

#endif // VIDEO_H
