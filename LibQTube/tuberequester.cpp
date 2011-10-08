#include "tuberequester.h"
#include <QUrl>
#include <QNetworkRequest>

const QString TubeRequester::BASE_URL("http://gdata.youtube.com/feeds/api/videos?");

TubeRequester::TubeRequester(QObject *parent)
    : QObject(parent)
    , m_networkManager()
    , m_request       ()
    , m_pReply         (0)
    , m_requestHash    ()

{

}

TubeRequester::~TubeRequester()
{
}

void TubeRequester::setNumberOfResult(int _nb)
{
    m_requestHash.insert("max-results", QString::number(_nb));
}

void TubeRequester::setQuery(const QString& _request)
{
    m_requestHash.insert("q", _request);
}

void TubeRequester::_prepareRequest(QNetworkReply* _reply)
{
    QIODevice *res = (QIODevice*)_reply;
    if( _reply )
        emit resultReady(res);
}

void TubeRequester::sendRequest()
{
    QNetworkRequest request;
    m_request = BASE_URL;
    foreach( QString key, m_requestHash.keys() ) {
        m_request.append(key);
        m_request.append("=");
        m_request.append(m_requestHash.value(key));
    }

    request.setUrl(QUrl(m_request));
    qDebug() << "req" << m_request;
    bool b = connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(_prepareRequest(QNetworkReply*)));
    qDebug() << "connect" << b;
    m_networkManager.get(request);
}
