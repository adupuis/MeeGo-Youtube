#include "tuberequester.h"

QString BASE_URL = "http://gdata.youtube.com/feeds/api/videos";

TubeRequester::TubeRequester(QObject *parent)
    : QObject(parent)
{
}

TubeRequester::~TubeRequester()
{
}

void TubeRequester::setNumberOfResult(int _nb)
{

}

void TubeRequester::setQuery(const QString& _request)
{

}


void TubeRequester::sendRequest()
{
}
