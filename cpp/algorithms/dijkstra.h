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
    std::vector<int> getPath() override;
    AlgoState state() override;

private:
    std::vector<int> neighbors(int current) override;
    void processNode(int current) override;

private:
    std::vector<int> m_cameFrom;
};


#endif
