#pragma once
#include "cpp/algorithms/tsp/itspalgorithm.h"
#include <qlist.h>
#include <vector>

class Bruteforce : public ITspAlgorithm {

public:
  void init(const QMap<QPair<int, int>, int> distanceMatrix, const int start,
            const QList<int> targets) override;
  TspStepResult step() override;

private:
  int calculateRouteDistance(const std::vector<int> &route);
  int m_start;
  bool m_finished;
  QList<int> m_targets;
  QMap<QPair<int, int>, int> m_matrix;
  std::vector<int> m_currentPath;
  QList<int> m_bestPath;
  int m_shortestDistance;
};
