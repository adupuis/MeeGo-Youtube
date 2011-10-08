#ifndef VIDEO_H
#define VIDEO_H

#include <QDate>

#include "category.h"

class Video : public QObject {
private:
    Category    category;
    QString     name;
    QString     id;             // Only the string after http://www.youtube.com/watch?v=
    QDate       pubDate;

public:
    // Constructor
                Video       (QString &id);

    // Getters
    Category    getCategory();
    QString&    getName();
    QString&    getId();
    QDate&      getPubDate();

    // Setters
    void        setCategory (Category *Category);
    void        setName     (QString &name);
    void        setPubDate  (QDate &date);
};

#endif // VIDEO_H
