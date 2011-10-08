#ifndef TUBEREQUESTER_H
#define TUBEREQUESTER_H

#include <QObject>
#include <QIODevice>
#include <QNetworkAccessManager>
#include <QHash>

#include <QDebug>

class TubeRequester : public QObject
{
    Q_OBJECT
public:
    static const QString BASE_URL;

    TubeRequester(QObject *parent = 0);
    virtual ~TubeRequester();

    void setNumberOfResult(int _nb);
    void setQuery(const QString& _request);

    // TODO add query params

    void sendRequest();
signals:
    void resultReady(QIODevice *_result);

private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_request;
    QNetworkReply*          m_pReply;
    QHash<QString,QString>  m_requestHash;
private slots:
    void _prepareRequest(QNetworkReply* _reply);

};

#endif // TUBEREQUESTER_H
