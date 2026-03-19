#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "ialgorithm.h"

class Dijkstra: public IAlgorithm
{
public:
    ~Dijkstra() override = default;
    void run(const GridData& data) override;
    void setState(const AlgoState algoState) override;
    void init(const GridData& data) override;
    int step() override;
    AlgoState state() override;

private:
    std::vector<int> neighbors(int current) override;
    void processNode(int current) override;

private:
    std::queue<int> m_queue;
    std::vector<bool> m_visited;
    GridData m_data;
    AlgoState m_state = AlgoState::Stopped;
};


#endif
