#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "algorithms/IAlgorithm.h"
#include <QObject>

class Pathfinding: public QObject
{
    Q_OBJECT

public:
    explicit Pathfinding(QObject *parent = nullptr);
    Q_INVOKABLE void setAlgorithm(int index);

private:
    std::unique_ptr<IAlgorithm> m_algorithm;
};

#endif
