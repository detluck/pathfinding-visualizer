#include "bruteforce.h"
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
}
QList<int> Bruteforce::solve() {
  if (m_targets.empty())
    return {m_start};

  QList<int> bestOrder;
  int shortestDistance = std::numeric_limits<int>::infinity();
  std::vector<int> currentRoute = {m_targets.begin(), m_targets.end()};
  // sort the vector so the next_permutation could work correctly
  std::sort(currentRoute.begin(), currentRoute.end());

  do {
    int distance = calculateRouteDistance(currentRoute);
    if (distance < shortestDistance) {
      shortestDistance = distance;

      bestOrder = {currentRoute.begin(), currentRoute.end()};
    }
  } while (std::next_permutation(currentRoute.begin(), currentRoute.end()));

  QList<int> finalPaht;
  finalPaht.append(m_start);
  finalPaht.append(bestOrder);

  return finalPaht;
}

int Bruteforce::calculateRouteDistance(const std::vector<int> &route) {
  int total = 0;
  int current = m_start;

  for (int next : route) {
    auto key = qMakePair(current, next);

    if (!m_matrix.contains(key))
      return std::numeric_limits<int>::infinity();
    total += m_matrix.value(key);

    current = next;
  }

  return total;
}
