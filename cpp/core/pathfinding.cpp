#include "pathfinding.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/bfs.h"
#include "cpp/algorithms/astar.h"
#include "cpp/algorithms/dijkstra.h"
#include "cpp/model/gridmodel.h"
#include <QDebug>

Pathfinding::Pathfinding(QObject *parent)
    :QObject(parent), m_model(new GridModel(this))
{
    timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, &QTimer::timeout, this, &Pathfinding::onStep);

    QSettings settings("GoonSoft", "Pathfinder");
    QVariant defaultWeights = QVariantList{10, 20, 40, 60, 80, 100};

    m_avilableWeights = settings.value("customWeights", defaultWeights).toList();
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
    case AlgorithmType::Bfs:
        m_algorithm = std::make_unique<Bfs>();
        qDebug() << "Bfs aktiv";
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
    emit clickTypeChanged();
}

Pathfinding::ClickType Pathfinding::clickType()
{
    return m_type;
}

int Pathfinding::currentWeight(){
    return m_currentWeight;
}

QVariantList Pathfinding::availableWeights(){
    return m_avilableWeights;
}

void Pathfinding::setCurrentWeight(const int weight){
    if(weight == m_currentWeight){
        return;
    }
    m_currentWeight = weight;
    emit currentWeightChanged();
}

void Pathfinding::setAvailableWeights(const QVariantList list){
    if(list == m_avilableWeights){
        return;
    }

    QVariantList validated;

    for(const QVariant &item: list){
        bool ok;
        int weight = item.toInt(&ok);

        if(ok && weight > 0 && !validated.contains(weight) && validated.size() < 12){
            validated.append(weight);
        }
    }

    if(m_avilableWeights != validated){
        m_avilableWeights = validated;

        QSettings settings("GoonSoft", "Pathfinder");
        settings.value("customWeights", m_avilableWeights);
        emit availableWeightsChanged();
    }
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

void Pathfinding::setWeightNode(const int index, const int weight)
{
    if(weight >= 0 && isValid(index)){
        m_model->setNodeType(NodeType::WeightNode, index, weight);
        qDebug() << "Weight set " << weight;
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
    if(m_algorithm && isValid(m_start) && isValid(m_end)){
        if(m_algorithm->state() == AlgoState::Stopped){
            m_model->clearVisited();
        }
        GridData data = collectData();
        m_algorithm->init(data);

        if(!timer->isActive()){
            timer->start();
        }
    }

    else {
        qDebug() << "Error: trying to start, but no algorithm selected or start/end index not valid!";
    }
}

void Pathfinding::stopAlgorithm()
{
    if(timer->isActive() && !paused){
        timer->stop();
        paused = true;
    }
    else if(!timer->isActive() && paused && m_type == ClickType::Pause){
        timer->start();
        paused = false;
    }
}

void Pathfinding::resumeAlgorithm()
{
    if(!timer->isActive()){
        timer->start();
    }
}

void Pathfinding::setSpeed(const int speed)
{
    if(speed == 0){
        timer->stop();

        while(true){
            auto result = m_algorithm->step();

            if(result.state == StepResultType::Finished){
                m_model->reconstructPath(m_algorithm->getPath());
                emit finished();
                break;
            }

            if(result.state == StepResultType::Running){
                m_model->setNodeType(NodeType::Visited, result.index);
            }
        }
        return;
    }

    bool wasRunning = timer->isActive();

    timer->stop();
    timer->setInterval(speed);

    if(wasRunning){
        timer->start();
    }
}

void Pathfinding::clearGrid()
{
    if(timer->isActive()){
        timer->stop();
    }
    m_model->clearModel();
    m_start = -1;
    m_end = -1;
}

void Pathfinding::deleateitem(const int index)
{
    if(timer->isActive()){
        timer->stop();
    }
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
        stopAlgorithm();
        break;
    case ClickType::Resume:
        startAlgorithm();
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
    case ClickType::WeightNode:
        setWeightNode(index, m_currentWeight);
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
    //my fix
    data.width = m_model->width();
    data.height = m_model->height();
    data.startIndex = m_start;
    data.endIndex = m_end;
    data.nodes = m_model->getNodes();

    return data;
}

void Pathfinding::onStep()
{
    if(!m_algorithm) {
        timer->stop();
        return;
    }
    auto result = m_algorithm->step();

    switch(result.state) {
        case StepResultType::Running:
            m_model->setNodeType(NodeType::Visited, result.index);
            break;
        case StepResultType::Paused:
            //do nothing
            break;
        case StepResultType::Finished:
            timer->stop();
            m_model->reconstructPath(m_algorithm->getPath());
            emit finished();
            break;
    }
}
