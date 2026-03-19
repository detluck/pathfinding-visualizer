#include "pathfinding.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/dijkstra.h"
#include "cpp/algorithms/astar.h"
#include "cpp/model/gridmodel.h"
#include <QDebug>

//Will be reworked
Pathfinding::Pathfinding(QObject *parent)
    :QObject(parent), m_model(new GridModel(this))
{
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

void Pathfinding::setClickType(ClickType type)
{
    if(type == m_type)
    {
        return;
    }
    m_type = type;
    qDebug() << "ClickType set" << type;
}

Pathfinding::ClickType Pathfinding::clickType()
{
    return m_type;
}

void Pathfinding::setStartIndex(const int index)
{
    if(m_start != -1)
    {
        qDebug() << "changing nodetype to empty";
        m_model->setNodeType(NodeType::Empty, m_start);
    }
    if(isValid(index))
    {
        m_start = index;
        qDebug() << "Setting start index in model";
        m_model->setNodeType(NodeType::Start, m_start);
    }
}

void Pathfinding::setEndIndex(const int index)
{
    if(m_end != -1)
    {
        m_model->setNodeType(NodeType::Empty, m_end);
    }
    if(isValid(index))
    {
        m_end = index;
        m_model->setNodeType(NodeType::End, m_end);
    }
}

void Pathfinding::setWallIndex(const int index)
{
    if(isValid(index))
    {
        m_model->setNodeType(NodeType::Wall, index);
    }
}

void Pathfinding::startAlgorithm()
{
    if(m_algorithm){
    GridData data = collectData();
    m_algorithm->run(data);
    }
}

void Pathfinding::pauseAlgorithm()
{
    if(m_algorithm)
    {
        m_algorithm->pause();
    }
}

void Pathfinding::resumeAlgorithm()
{
    if(m_algorithm)
    {
        m_algorithm->resume();
    }
}

void Pathfinding::stopAlgorithm()
{
    if(m_algorithm)
    {
        m_algorithm->stop();
    }
}

void Pathfinding::clearGrid()
{
    m_model->clearModel();
}

void Pathfinding::deleateitem(const int index)
{
    if(isValid(index)){
    m_model->setNodeType(NodeType::Empty, index);
    }
}

bool Pathfinding::isValid(const int index)
{
    return index >= 0 && index < m_model->rowCount();
}

void Pathfinding::handleClick(const int index)
{
    switch(m_type)
    {
    case ClickType::Start:
        startAlgorithm();
        break;
    case ClickType::Pause:
        pauseAlgorithm();
        break;
    case ClickType::Resume:
        resumeAlgorithm();
        break;
    case ClickType::Stop:
        stopAlgorithm();
        break;
    case ClickType::Clear:
        clearGrid();
        break;
    case ClickType::StartNode:
        qDebug() << "Starting startNode";
        setStartIndex(index);
        break;
    case ClickType::TargetNode:
        setEndIndex(index);
        break;
    case ClickType::Deleate:
        deleateitem(index);
        break;
    case ClickType::Wall:
        setWallIndex(index);
        break;
    default:
        break;
    }
}

GridModel *Pathfinding::gridModel()
{
    return m_model;
}

GridData Pathfinding::collectData()
{
    GridData data;
    std::vector<NodeType> types;
    data.width = m_model->width();
    data.height = m_model->height();
    data.startIndex = m_start;
    data.endIndex = m_end;
    data.nodes = m_model->nodeTypes();
    return data;
}
