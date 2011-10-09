#include "tuberequester.h"

TubeRequester::TubeRequester(QObject *parent)
    : TubeRequesterBase(parent)
{
}

TubeRequester::~TubeRequester()
{

}


void TubeRequester::setQuery(const QString& _request)
{
    m_requestHash.insert("q", _request);
}

void TubeRequester::addCategory(Category _cat)
{
    m_categories.insert(_cat);
}

void TubeRequester::setFormatEmbeddable()
{
    m_isEmbeddable = false;
}

void TubeRequester::setNumberOfResult(int _nb)
{
    TubeRequesterBase::setNumberOfResult(_nb);
}
