#ifndef TUBEREQUESTER_H
#define TUBEREQUESTER_H

#include <tuberequesterbase.h>
#include <QObject>
#include <QString>

class TubeRequester : public TubeRequesterBase
{
public:
    TubeRequester(QObject *parent = 0);
    ~TubeRequester();

    void setQuery(const QString& _request);
    void addCategory(Category _cat);
    void setFormatEmbeddable();
    void setNumberOfResult(int _nb);

private :

};

#endif // TUBEREQUESTER_H
