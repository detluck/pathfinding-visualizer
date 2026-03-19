#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "ialgorithm.h"

class Worker: public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject* parent = nullptr);
    void setAlgorithm(IAlgorithm* algorithm);

public slots:
    void process();
    void pause();
    void resume();
    void stop();

signals:
    void finished();
    void nodeVisited(int index);

private:
    IAlgorithm* m_algorithm = nullptr;
};

#endif // WORKER_H
