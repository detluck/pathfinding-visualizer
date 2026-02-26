#include "pathfinding.h"
#include "algorithmType.h"
#include "algorithms/dijkstra.h"
#include "algorithms/astar.h"
#include <iostream>

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
        std::cout << "Dijkstra aktiv";
        break;
    case AlgorithmType::Astar:
        m_algorithm = std::make_unique<AStar>();
        std::cout << "AStar aktiv";
        break;
    default:
        break;
    }
}
