#include "pathfinding.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/dijkstra.h"
#include "cpp/algorithms/astar.h"
#include "cpp/model/gridmodel.h"
#include <QDebug>

//Will be reworked
Pathfinding::Pathfinding(QObject *parent)
    :QObject(parent)
{
    connect(this, &Pathfinding::clickTypeChanged, this, &Pathfinding::handleClick);
}

void Pathfinding::setAlgorithm(int index)
{
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

void Pathfinding::handleClick(int index)
{
    //Not finished
    switch(m_type)
    {
    case ClickType::Start:
        Pathfinding::startAlgorithm();
        break;
    case ClickType::Pause:
        m_algorithm->pause();
        break;
    case ClickType::Resume:
        m_algorithm->resume();
        break;
    case ClickType::Stop:
        m_algorithm->stop();
        break;
    case ClickType::Clear:
        m_model->clearModel();
        break;
    case ClickType::StartNode:
        setStartIndex(index);
        break;
    case ClickType::TargetNode:
        setEndIndex(index);
        break;
    case ClickType::Deleate:
        break;
    case ClickType::Wall:
        break;
    default:
        break;
    }
}

void Pathfinding::setClickType(ClickType type)
{
    m_type = type;
    emit clickTypeChanged();
}

void Pathfinding::setStartIndex(int index)
{
    if(index >= 0 || index <= m_model->rowCount())
    {
        m_start = index;
    }
}

void Pathfinding::setEndIndex(int index)
{
    if(index >= 0 || index <= m_model->rowCount())
    {
        m_end = index;
    }
}

void Pathfinding::setWallIndex(int index)
{

}

void Pathfinding::startAlgorithm()
{
    GridData data = collectData();
    m_algorithm->run(data);
}

GridData Pathfinding::collectData()
{
    GridData data;
    std::vector<NodeType> types;
    data.width = m_model->width();
    data.height = m_model->height();
    data.startIndex = m_start;
    data.endIndex = m_end;
    types = m_model->nodeTypes();
    return data;
}



Pathfinding::ClickType Pathfinding::clickType()
{
    return m_type;
}
