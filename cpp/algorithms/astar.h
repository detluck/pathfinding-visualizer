#ifndef ASTAR_H
#define ASTAR_H
#include "ialgorithm.h"

class AStar: public IAlgorithm
{
public:
    ~AStar() override = default;
    void run(const GridData& data) override;
    void setState(const AlgoState algoState) override;
    void init(const GridData& data) override;
    StepResult step() override;
    std::vector<int> getPath() override;
    AlgoState state() override;
    void blazzingRun() override;

private:
    std::vector<int> neighbors(int current) override;
    void processNode(int current) override;
};

#endif
