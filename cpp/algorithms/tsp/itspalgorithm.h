#pragma once
#include "../algorithmType.h"
#include <QList>
#include <QMap>
#include <QPair>
#include <qlist.h>
#include <qmap.h>

struct TspStepResult {
  StepResultType state;
  QList<int> currentPath;
  QList<int> bestPathSoFar;
};
class ITspAlgorithm {
public:
  virtual void init(const QMap<QPair<int, int>, int> distanceMatrix,
                    const int start, const QList<int> targets) = 0;
  virtual TspStepResult step() = 0;
};
