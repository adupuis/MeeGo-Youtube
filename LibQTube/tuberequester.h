#ifndef TUBEREQUESTER_H
#define TUBEREQUESTER_H

#include <QObject>
#include <QIODevice>

class TubeRequester : QObject
{
    Q_OBJECT
public:
    static const QString BASE_URL;

    TubeRequester(QObject *parent);
    virtual ~TubeRequester();

    void setNumberOfResult(int _nb);
    void setQuery(const QString& _request);

    // TODO add query params

    void sendRequest();
signals:
    void resultReady(const QIODevice &_result);

private:

};

#endif // TUBEREQUESTER_H
