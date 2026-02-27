#include "pathfinding.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/dijkstra.h"
#include "cpp/algorithms/astar.h"
#include <iostream>
#include <QDebug>

Pathfinding::Pathfinding(QObject *parent)
    :QObject(parent)
{}

void Pathfinding::setAlgorithm(int index){
    if(index < 0 || index>= static_cast<int>(AlgorithmType::Count)){
        return;
    }
    auto type = static_cast<AlgorithmType>(index);

    switch(type)
    {
    case AlgorithmType::Dijkstra:
        m_algorithm = std::make_unique<Dijkstra>();
        qDebug() << "Dijkstra aktiv";
        break;
    case AlgorithmType::Astar:
        m_algorithm = std::make_unique<AStar>();
        qDebug() << "AStar aktiv";
        break;
    default:
        break;
    }
}
