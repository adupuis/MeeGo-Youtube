#ifndef REQUESTABLE_H
#define REQUESTABLE_H

#include <QObject>

/*
 * This interface is used fo objects which have a "query" API for videos
 *   Category, Keyword, User, Video (videos must return related, but can
 *   also have responses)
 */
class Requestable : public QObject
{
public:
    virtual void request() = 0;
};

#endif // REQUESTABLE_H
