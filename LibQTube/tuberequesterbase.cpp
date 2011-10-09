#include "tuberequesterbase.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

const QString TubeRequesterBase::BASE_URL("http://gdata.youtube.com/feeds/mobile/videos");
const QString TubeRequesterBase::CAT_PREFIX("{http://gdata.youtube.com/schemas/2007/categories.cat}");
QList<QString> TubeRequesterBase::CATEGORIES;

TubeRequesterBase::TubeRequesterBase(QObject *parent)
    : QObject(parent)
    , m_networkManager()
    , m_request       ()
    , m_pReply        (0)
    , m_requestHash   ()
    , m_isEmbeddable  (false)

{
    m_requestHash.insert("alt", "rss");
    //FIXME: hard coded...
    // see Categories enum
    CATEGORIES.append(QString("Autos"));
    CATEGORIES.append(QString("Comedy"));
    CATEGORIES.append(QString("Education"));
    CATEGORIES.append(QString("Entertainment"));
    CATEGORIES.append(QString("Film"));
    CATEGORIES.append(QString("Howto"));
    CATEGORIES.append(QString("Music"));
    CATEGORIES.append(QString("News"));
    CATEGORIES.append(QString("People"));
    CATEGORIES.append(QString("Animals"));
    CATEGORIES.append(QString("Tech"));
    CATEGORIES.append(QString("Sports"));
    CATEGORIES.append(QString("Travel"));

    m_request = BASE_URL;
}

TubeRequesterBase::~TubeRequesterBase()
{
    if(m_pReply)
        m_pReply->deleteLater();
}

void TubeRequesterBase::setNumberOfResult(int _nb)
{
    m_requestHash.insert("max-results", QString::number(_nb));
}

void TubeRequesterBase::_prepareRequest(QNetworkReply* _reply)
{
    QIODevice *res = 0;
    if(_reply->error() == QNetworkReply::NoError) {
        res = (QIODevice*)_reply;
    }
    emit resultReady(res);
}

void TubeRequesterBase::sendRequest()
{
    QNetworkRequest request;
    bool isFirst = true;

    // categories
    if( m_categories.size() != 0 ) {
        m_request.append("/-");
        foreach(Category cat, m_categories) {
            m_request.append("/");
            m_request.append(QUrl::toPercentEncoding(CAT_PREFIX));
            QString strCat = CATEGORIES.value(cat);
            Q_ASSERT(strCat.isNull() == false);
            m_request.append(QUrl::toPercentEncoding(strCat));
        }
    }

    {// param
        int count = 0;
        const QList<QString> &keys = m_requestHash.keys();
        if(keys.isEmpty() == false)
            isFirst = false;
        foreach( QString key, keys ) {
            if(count == 0)
                m_request.append("?");
            m_request.append(key);
            m_request.append("=");
            m_request.append(m_requestHash.value(key));
            if(count != keys.length() - 1)
                m_request.append("&");
            count++;
        }
    }

    // format
    if(m_isEmbeddable) {
        if(isFirst)
            m_request.append("?");
        else
            m_request.append("&");
        m_request.append("format=5");
    }

    request.setUrl(QUrl(m_request));
    request.setRawHeader("GData-Version", "2");
    qDebug() << "req" << request.url();
    connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(_prepareRequest(QNetworkReply*)));
    m_networkManager.get(request);
}
