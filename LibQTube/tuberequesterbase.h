#ifndef TUBEREQUESTERBASE_H
#define TUBEREQUESTERBASE_H

#include <QObject>
#include <QIODevice>
#include <QNetworkAccessManager>
#include <QHash>
#include <QSet>

class TubeRequesterBase : public QObject
{
    Q_OBJECT
public:
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

    void sendRequest();

protected:
    TubeRequesterBase(QObject *parent = 0);
    virtual ~TubeRequesterBase();
    void setNumberOfResult(int _nb);
signals:
    /**
      * @return: may be null if error.
      */
    void resultReady(QIODevice *_result);

protected:
    QNetworkAccessManager   m_networkManager;
    QString                 m_request;
    QNetworkReply*          m_pReply;
    QHash<QString,QString>  m_requestHash;
    QSet<Category>          m_categories;
    bool                    m_isEmbeddable;
    static QList<QString>   CATEGORIES;
    static const QString    BASE_URL;
    static const QString    CAT_PREFIX;
private slots:
    void _prepareRequest(QNetworkReply* _reply);
};

#endif // TUBEREQUESTERBASE_H
