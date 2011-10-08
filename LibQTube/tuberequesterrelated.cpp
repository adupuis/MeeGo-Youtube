#include "tuberequesterrelated.h"

TubeRequesterRelated::TubeRequesterRelated(QObject *parent)
    : TubeRequesterBase(parent)
{
}


TubeRequesterRelated::~TubeRequesterRelated()
{
}

void TubeRequesterRelated::setNumberOfResult(int _nb)
{
    TubeRequesterBase::setNumberOfResult(_nb);
}

void TubeRequesterRelated::setId(const QString &_id)
{
    m_request = "http://gdata.youtube.com/feeds/api/videos/" + _id + "/related";
}

