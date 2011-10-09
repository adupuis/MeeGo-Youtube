#ifndef APP_H
#define APP_H
#include <QObject>
#include <QIODevice>
#include <QDebug>
#include <tuberequester.h>
#include <tuberequesterrelated.h>
class App : public QObject {
    Q_OBJECT
public:
    App() {
        TubeRequester* tr = new TubeRequester(this);
        connect(tr, SIGNAL(resultReady(QIODevice*)), this, SLOT(print(QIODevice*)));
        tr->setNumberOfResult(3);
//        tr->setQuery("plop");
        tr->addCategory(TubeRequester::Autos);
        tr->addCategory(TubeRequester::Animals);
        tr->setFormatEmbeddable();
        tr->sendRequest();

        TubeRequesterRelated* trr = new TubeRequesterRelated(this);
        connect(tr, SIGNAL(resultReady(QIODevice*)), this, SLOT(print(QIODevice*)));
        trr->setNumberOfResult(3);
        trr->setId("42");
//        tr->setQuery("plop");
//        tr->addCategory(TubeRequester::Autos);
//        tr->addCategory(TubeRequester::Animals);
//        tr->setFormatEmbeddable();
        trr->sendRequest();
    }
public slots:
    void print(QIODevice* d) {
        if( d != 0) {
            QByteArray bytes;
            do{
                bytes = d->readLine();
                qDebug() << bytes;
            }while(bytes.length() != 0);
        }else{
            qDebug() << "fail";
        }
    }
};

#endif // APP_H
