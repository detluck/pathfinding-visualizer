#ifndef IALGORITHM_H
#define IALGORITHM_H
#include "cpp/model/node.h"
#include <vector>

struct GridData{
    std::vector<Node> nodes;
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

enum class StepResultType{
    Running,
    Paused,
    Finished
};

struct StepResult {
    StepResultType state;
    int index;
};

class IAlgorithm{
public:
    virtual ~IAlgorithm() = default;
    virtual void run(const GridData& data) = 0;
    virtual void setState(const AlgoState algoState) = 0;
    virtual void init(const GridData& data) = 0;
    virtual StepResult step() = 0;
    virtual std::vector<int> getPath() = 0;
    virtual AlgoState state() = 0;

private:
    virtual std::vector<int> neighbors(int current) = 0;
    virtual void processNode(int current) = 0;
};

#endif // IALGORITHM_H
