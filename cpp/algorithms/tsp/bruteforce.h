#pragma once
#include "cpp/algorithms/tsp/itspalgorithm.h"
#include <vector>

class Bruteforce : ITspAlgorithm {

public:
  void init(const QMap<QPair<int, int>, int> distanceMatrix, const int start,
            const QList<int> targets) override;
  QList<int> solve() override;

private:
  int calculateRouteDistance(const std::vector<int> &route);
  int m_start;
  QList<int> m_targets;
  QMap<QPair<int, int>, int> m_matrix;
};
