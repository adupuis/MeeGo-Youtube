#include "video.h"

Video::Video(QString &id) {
    m_id = id;
}

Video::Video(QString &id, Category *category, User *author) {
    m_id = id;
    m_category = category;
    m_author = author;

    setParent(category);
}

Category* Video::getCategory() {
    return m_category;
}

User* Video::getAuthor() {
    return m_author;
}

QString& Video::getName() {
    return m_name;
}

QString& Video::getId() {
    return m_id;
}

QDateTime& Video::getPubDate() {
    return m_pubDate;
}

QString& Video::getDescription() {
    return m_description;
}

qint32 Video::getDuration() {
    return m_duration;
}

qint32 Video::getFavoriteCount() {
    return m_favoriteCount;
}

qint32 Video::getViewCount() {
    return m_viewCount;
}

qint32 Video::getDislikes() {
    return m_dislikes;
}

qint32 Video::getLikes() {
    return m_likes;
}

qreal Video::getRating() {
    return m_rating;
}

qint32 Video::getNumRating() {
    return m_numRating;
}

void Video::setCategory(Category *category) {
    m_category = category;
}

void Video::setAuthor(User *author) {
    m_author = author;
}

void Video::setName(QString &name) {
    m_name = name;
}

void Video::setPubDate(QDateTime &date) {
    m_pubDate = date;
}

void Video::setDescription(QString &description) {
    m_description = description;
}

void Video::setDuration(qint32 duration) {
    m_duration = duration;
}

void Video::setFavoriteCount(qint32 count) {
    m_favoriteCount = count;
}

void Video::setViewCount(qint32 count) {
    m_viewCount = count;
}

void Video::setDislikes(qint32 count) {
    m_dislikes = count;
}

void Video::setLikes(qint32 count) {
    m_likes = count;
}

void Video::setRating(qreal rating) {
    m_rating = rating;
}

void Video::setNumRating(qint32 count) {
    m_numRating = count;
}

void Video::retrieve() {
    // TODO
}
