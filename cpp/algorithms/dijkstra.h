#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "ialgorithm.h"
#include <queue>

struct NodeRecord {
  int index;
  int cost;

  bool operator>(const NodeRecord &other) const { return cost > other.cost; }
};

class Dijkstra : public IAlgorithm {
public:
  ~Dijkstra() override = default;
  void run(const GridData &data) override;
  void setState(const AlgoState algoState) override;
  void init(const GridData &data) override;
  StepResult step() override;
  std::vector<int> getPath() override;
  AlgoState state() override;
  void init(const GridData &data, int start);
  std::vector<int> getPath(int end);

private:
  std::vector<int> neighbors(int current) override;
  void processNode(int current) override;

private:
  std::vector<int> m_cameFrom;

  std::priority_queue<NodeRecord, std::vector<NodeRecord>,
                      std::greater<NodeRecord>>
      m_queue;

  std::vector<int> m_costs;

  std::vector<bool> m_visited;
  GridData m_data;
  AlgoState m_state = AlgoState::Stopped;
};

#endif // DIJKSTRA_H
