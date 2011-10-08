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
    static const QString CAT_PREFIX;

    enum Category {
        Autos = 0 ,
        Comedy,
        Education,
        Entertainment,
        Film,
        Howto,
        Music,
        News,
        People,
        Animals,
        Tech,
        Sports,
        Travel,
        _ENUM_SIZE
    };

    TubeRequester(QObject *parent = 0);
    virtual ~TubeRequester();

    void setNumberOfResult(int _nb);
    void setQuery(const QString& _request);
    void addCategory(Category _cat);
    // TODO add query params

    void sendRequest();
signals:
    /**
      * @return: may be null if error.
      */
    void resultReady(QIODevice *_result);

private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_request;
    QNetworkReply*          m_pReply;
    QHash<QString,QString>  m_requestHash;
    QSet<Category>          m_categories;
    static QList<QString>   CATEGORIES;
private slots:
    void _prepareRequest(QNetworkReply* _reply);

};

#endif // TUBEREQUESTER_H
