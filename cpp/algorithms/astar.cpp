#include "astar.h"

void AStar::run(const GridData& data) {}
void AStar::setState(const AlgoState algoState) {}
void AStar::init(const GridData& data) {}
StepResult AStar::step() { return {StepResultType::Finished, -1}; }
std::vector<int> AStar::getPath() { return {}; }
AlgoState AStar::state() { return AlgoState::Stopped; }
void AStar::blazzingRun() {}
std::vector<int> AStar::neighbors(int current) { return {}; }
void AStar::processNode(int current) {}