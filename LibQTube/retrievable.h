#ifndef RETRIEVABLE_H
#define RETRIEVABLE_H

#include <QObject>

/*
 * This interface is used fo objects which have a "get" API
 *   User, Playlist, Playlist entry
 */
class Retrievable : public QObject
{
public:
    virtual void retrieve() = 0;
};

#endif // RETRIEVABLE_H
