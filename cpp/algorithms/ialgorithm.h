#ifndef IALGORITHM_H
#define IALGORITHM_H
#include "cpp/model/node.h"
#include <vector>

struct GridData{
    std::vector<NodeType> nodes;
    int width;
    int height;
    int startIndex;
    int endIndex;
};

class IAlgorithm{
public:
    virtual ~IAlgorithm() = default;
    virtual void run(const GridData& data) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;

    virtual bool isRunning() const = 0;
};

#endif // IALGORITHM_H
