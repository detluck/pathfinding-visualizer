#pragma once
#include <QList>
#include <QMap>
#include <QPair>
#include <qmap.h>

class ITspAlgorithm {
public:
  virtual void init(const QMap<QPair<int, int>, int> distanceMatrix,
                    const int start, const QList<int> targets) = 0;
  virtual QList<int> solve() = 0;
};
