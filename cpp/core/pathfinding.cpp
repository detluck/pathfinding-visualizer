#include "pathfinding.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/astar.h"
#include "cpp/algorithms/bfs.h"
#include "cpp/algorithms/dijkstra.h"
#include "cpp/model/gridmodel.h"
#include <QDebug>
#include <algorithm>

Pathfinding::Pathfinding(QObject *parent)
    : QObject(parent), m_model(new GridModel(this)) {
  timer = new QTimer(this);
  timer->setInterval(50);
  connect(timer, &QTimer::timeout, this, &Pathfinding::onStep);

  QSettings settings("GoonSoft", "Pathfinder");
  QVariant defaultWeights = QVariantList{10, 20, 40, 60, 80, 100};

  m_availableWeights = settings.value("customWeights", defaultWeights).toList();
}

void Pathfinding::setAlgorithm(int index) {
  if (index < 0 || index >= static_cast<int>(AlgorithmType::Count)) {
    return;
  }
  auto type = static_cast<AlgorithmType>(index);

  switch (type) {
  case AlgorithmType::Dijkstra:
    m_algorithm = std::make_unique<Dijkstra>();
    emit toast("Dijkstra aktivated", 1);
    break;
  case AlgorithmType::Astar:
    m_algorithm = std::make_unique<AStar>();
    emit toast("A* aktivated", 1);
    break;
  case AlgorithmType::Bfs:
    m_algorithm = std::make_unique<Bfs>();
    emit toast("Dijkstra aktivated", 1);
    break;
  default:
    break;
  }
}

void Pathfinding::setClickType(ClickType type) {
  if (type == m_type) {
    return;
  }
  m_type = type;
  emit clickTypeChanged();
}

Pathfinding::ClickType Pathfinding::clickType() { return m_type; }

int Pathfinding::currentWeight() { return m_currentWeight; }

QVariantList Pathfinding::availableWeights() { return m_availableWeights; }

void Pathfinding::setCurrentWeight(const int weight) {
  if (weight == m_currentWeight) {
    return;
  }
  m_currentWeight = weight;
  emit currentWeightChanged();
  emit toast("Weight " + QString::number(m_currentWeight) + " was selected", 1);
}

void Pathfinding::setAvailableWeights(const QVariantList list) {
  if (list == m_availableWeights) {
    return;
  }

  QVariantList validated;

  for (const QVariant &item : list) {
    bool ok;
    int weight = item.toInt(&ok);

    if (ok && weight > 0 && !validated.contains(weight) &&
        validated.size() < 12) {
      validated.append(weight);
    }
  }

  if (m_availableWeights != validated) {
    m_availableWeights = validated;

    QSettings settings("GoonSoft", "Pathfinder");
    settings.value("customWeights", m_availableWeights);
    emit availableWeightsChanged();
  }
}

void Pathfinding::setStartIndex(const int index) {
  if (m_start != -1) {
    m_model->setNodeType(NodeType::Empty, m_start);
  }
  if (isValid(index)) {
    m_start = index;
    m_model->setNodeType(NodeType::Start, m_start);
  }
}

void Pathfinding::setEndIndex(const int index) {
  if (m_end != -1) {
    m_model->setNodeType(NodeType::Empty, m_end);
  }
  if (isValid(index)) {
    m_end = index;
    m_model->setNodeType(NodeType::End, m_end);
  }
}

void Pathfinding::setWeightNode(const int index, const int weight) {
  if (weight >= 0 && isValid(index)) {
    m_model->setNodeType(NodeType::WeightNode, index, weight);
    emit toast("Weight was set: " + QString::number(weight), 1);
  }
}

void Pathfinding::setWallIndex(const int index) {
  if (isValid(index)) {
    m_model->setNodeType(NodeType::Wall, index);
  }
}

void Pathfinding::startAlgorithm() {
  if (m_algorithm) {
    if (isValid(m_start) && isValid(m_end)) {
      if (m_algorithm->state() == AlgoState::Stopped) {
        m_model->clearVisited();
      }
      GridData data = collectData();
      m_algorithm->init(data);

      if (!timer->isActive()) {
        timer->start();
      }
    } else {
      emit toast("No start or end node with valid index", 2);
    }
  }

  else {
    emit toast("No algorithm has been set", 2);
  }
}

void Pathfinding::stopAlgorithm() {
  if (timer->isActive() && !paused) {
    timer->stop();
    paused = true;
  } else if (!timer->isActive() && paused && m_type == ClickType::Pause) {
    timer->start();
    paused = false;
  }
}

void Pathfinding::resumeAlgorithm() {
  if (!timer->isActive()) {
    timer->start();
  }
}

void Pathfinding::setSpeed(const int speed) {
  if (speed == 100) {
        timer->setInterval(0);

      if(timer->isActive()){
        timer->stop();
          timer->start();

        emit finished();
        emit toast("Blazing run finished", 1);
      }
    return;
  }
  int sppedDelay = (100 - speed);
  if (sppedDelay < 1)
    sppedDelay = 1;

  timer->setInterval(sppedDelay);

  if (timer->isActive()) {
    timer->stop();
    timer->start();
  }
}

void Pathfinding::clearGrid() {
  if (timer->isActive()) {
    timer->stop();
  }
  m_model->clearModel();
  m_start = -1;
  m_end = -1;
}

void Pathfinding::deleateitem(const int index) {
  if (timer->isActive()) {
    timer->stop();
  }
  if (isValid(index)) {
    m_model->setNodeType(NodeType::Empty, index);
  }
}

bool Pathfinding::isValid(const int index) {
  return index >= 0 && index < m_model->rowCount();
}

void Pathfinding::handleClick(const int index) {
  switch (m_type) {
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

void Pathfinding::addWeight(const int weight) {
  if (weight <= 1 || weight > 1000) {
    return;
  }
  if (m_availableWeights.contains(weight)) {
    setCurrentWeight(weight);
    return;
  }
  m_availableWeights.append(weight);
  std::sort(m_availableWeights.begin(), m_availableWeights.end(),
            [](const QVariant &a, const QVariant &b) {
              return a.toInt() < b.toInt();
            });
  if (m_availableWeights.contains(weight)) {
    emit toast("New weight added", 1);
  }

  emit availableWeightsChanged();
}

GridModel *Pathfinding::gridModel() { return m_model; }

GridData Pathfinding::collectData() {
  GridData data;
  std::vector<NodeType> types;
  // my fix
  data.width = m_model->width();
  data.height = m_model->height();
  data.startIndex = m_start;
  data.endIndex = m_end;
  data.nodes = m_model->getNodes();

  return data;
}

void Pathfinding::onStep() {
  if (!m_algorithm) {
    timer->stop();
    return;
  }
  auto result = m_algorithm->step();

  switch (result.state) {
  case StepResultType::Running:
    m_model->setNodeType(NodeType::Visited, result.index);
    break;
  case StepResultType::Paused:
    // do nothing
    break;
  case StepResultType::Finished:
    timer->stop();
    m_model->reconstructPath(m_algorithm->getPath());
    emit finished();
    emit toast("Finished", 1);
    break;
  }
}
