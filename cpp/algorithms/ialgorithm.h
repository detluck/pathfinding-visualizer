#ifndef IALGORITHM_H
#define IALGORITHM_H
#include "cpp/model/node.h"
#include <vector>
#include <queue>

struct GridData{
    std::vector<NodeType> nodes;
    int width;
    int height;
    int startIndex;
    int endIndex;
};

enum class AlgoState{
    Running,
    Paused,
    Stopped
};

class IAlgorithm{
public:
    virtual ~IAlgorithm() = default;
    virtual void run(const GridData& data) = 0;
    virtual void setState(const AlgoState algoState) = 0;
    virtual void init(const GridData& data) = 0;
    virtual int step() = 0;
    virtual AlgoState state() = 0;

private:
    virtual std::vector<int> neighbors(int current) = 0;
    virtual void processNode(int current) = 0;

private:
    std::queue<int> m_queue;
    std::vector<bool> m_visited;
    GridData m_data;
    AlgoState m_state = AlgoState::Stopped;
};

#endif // IALGORITHM_H
