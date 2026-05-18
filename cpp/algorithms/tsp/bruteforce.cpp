#include "bruteforce.h"
#include "cpp/algorithms/algorithmType.h"
#include "cpp/algorithms/tsp/itspalgorithm.h"
#include <algorithm>
#include <limits>
#include <qlist.h>
#include <qnamespace.h>
#include <qpair.h>

void Bruteforce::init(const QMap<QPair<int, int>, int> distanceMatrix,
                      const int start, const QList<int> targets) {
  m_start = start;
  m_matrix = distanceMatrix;
  m_targets = targets;
  m_finished = false;
  m_shortestDistance = std::numeric_limits<int>::max();
  m_currentPath = {m_targets.begin(), m_targets.end()};
  // sort the vector so the next_permutation could work correctly
  std::sort(m_currentPath.begin(), m_currentPath.end());
}
TspStepResult Bruteforce::step() {
  if (m_finished || m_targets.empty())
    return {StepResultType::Finished, m_bestPath};

  int distance = calculateRouteDistance(m_currentPath);
  if (distance < m_shortestDistance) {
    m_shortestDistance = distance;

    m_bestPath = {m_currentPath.begin(), m_currentPath.end()};
  }

  QList<int> stepPath = QList<int>(m_currentPath.begin(), m_currentPath.end());

  if (!std::next_permutation(m_currentPath.begin(), m_currentPath.end())) {
    m_finished = true;
    return {StepResultType::Finished, stepPath};
  }

  return {StepResultType::Running, stepPath};
}

int Bruteforce::calculateRouteDistance(const std::vector<int> &route) {
  int total = 0;
  int current = m_start;

  for (int next : route) {
    auto key = qMakePair(current, next);

    if (!m_matrix.contains(key))
      return std::numeric_limits<int>::max();
    total += m_matrix.value(key);

    current = next;
  }
  auto returnKey = qMakePair(current, m_start);
  if (!m_matrix.contains(returnKey)) {
    return std::numeric_limits<int>::max();
  }
  total += m_matrix.value(returnKey);

  return total;
}
