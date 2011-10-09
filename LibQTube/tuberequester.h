#ifndef TUBEREQUESTER_H
#define TUBEREQUESTER_H

#include <tuberequesterbase.h>
#include <QObject>
#include <QString>

/**
 * To use this class to request a list of videos:
 *
 * 1) Create a class which has a method void resultReady(QIODevice*).
 * 2) Create an instance of TubeRequester.
 * 3) Connect your class's resultReady method to the TubeRequester.resultReady signal:
 *
 *     QObject::connect(&tubeRequester, SIGNAL(resultReady(QIODevice*)), this, SLOT(resultReady(QIODevice*)));
 *
 * 4) In your class' resultReady(QIODevice*) method, use the QTubeParser to retrieve the videos.
 * 5) Call methods on TubeRequester to filter out the requests.
 * 6) Call TubeRequester.sendRequest().
 */
class TubeRequester : public TubeRequesterBase
{
public:
    TubeRequester(QObject *parent = 0);
    ~TubeRequester();

    void setQuery(const QString& _request);
    void addCategory(Category _cat);
    void setFormatEmbeddable();
    void setNumberOfResult(int _nb);

private :

};

#endif // TUBEREQUESTER_H
