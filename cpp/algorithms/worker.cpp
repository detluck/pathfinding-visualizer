#include "worker.h"
#include <QThread>

void Worker::setAlgorithm(IAlgorithm *algorithm)
{
    if(m_algorithm != algorithm){
        m_algorithm = algorithm;
    }
}

void Worker::process()
{
    m_algorithm->setState(AlgoState::Running);
    while(true){

        if(m_algorithm->state() == AlgoState::Paused){
            QThread::msleep(20);
            continue;
        }
        int index = m_algorithm->step();

        if(index == -1){
            break;
        }

        emit nodeVisited(index);
        QThread::msleep(20);
    }
    emit finished();
}

void Worker::pause()
{
    m_algorithm->setState(AlgoState::Paused);
}

void Worker::resume()
{
    m_algorithm->setState(AlgoState::Running);
}

void Worker::stop()
{
    m_algorithm->setState(AlgoState::Stopped);
}
