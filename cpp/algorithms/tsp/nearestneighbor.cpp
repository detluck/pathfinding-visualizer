#include "cpp/algorithms/tsp/nearestneighbor.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/tsp/itspalgorithm.h"
#include <limits>
#include <qdebug.h>
#include <qpair.h>
void NearestNeighbor::init(const QMap<QPair<int, int>, int> distanceMatrix,
                           const int start, const QList<int> targets) {
  m_start = start;
  m_currentNeighbor = start;
  m_matrix = distanceMatrix;
  m_targets = targets;
  m_finished = false;
  m_currentPath.clear();
}

TspStepResult NearestNeighbor::step() {
  if (m_finished || m_targets.empty())
    return {StepResultType::Finished, m_currentPath};

  int shortestDistance = std::numeric_limits<int>::max();
  int nearestNeigbor = -1;
  for (int neigbor : m_targets) {
    auto key = qMakePair(m_currentNeighbor, neigbor);
    if (m_matrix.contains(key)) {
      int distance = m_matrix.value(key);
      if (shortestDistance > distance) {
        shortestDistance = distance;
        nearestNeigbor = neigbor;
      }
    }
  }
  qDebug() << "shortestDistance " << shortestDistance << "nearestNeigbor "
           << nearestNeigbor;
  if (nearestNeigbor != -1) {
    m_targets.removeOne(nearestNeigbor);
    m_currentPath.append(nearestNeigbor);
    m_currentNeighbor = nearestNeigbor;
  } else {
    m_finished = true;
    return {StepResultType::Finished, m_currentPath};
  }

  return {StepResultType::Running, m_currentPath};
}
