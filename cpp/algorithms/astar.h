#ifndef ASTAR_H
#define ASTAR_H
#include "ialgorithm.h"

class AStar: public IAlgorithm
{
public:
    ~AStar() override = default;
    void run(const GridData& data) override;

private:
};


#endif
