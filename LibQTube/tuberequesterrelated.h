#ifndef TUBEREQUESTERRELATED_H
#define TUBEREQUESTERRELATED_H

#include <tuberequesterbase.h>

class TubeRequesterRelated : public TubeRequesterBase
{
public:
    TubeRequesterRelated(QObject *parent);
    ~TubeRequesterRelated();

    void setNumberOfResult(int _nb);
    void setId(const QString &_id);
};

#endif // TUBEREQUESTERRELATED_H
