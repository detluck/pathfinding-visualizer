#ifndef ASTAR_H
#define ASTAR_H
#include "IAlgorithm.h"
#include <atomic>

class AStar: public IAlgorithm
{
public:
    ~AStar() override = default;
    void run() override;
    void pause() override;
    void resume() override;
    void stop() override;

    bool isRunning() const override;

private:
    std::atomic<bool> running {false};
    std::atomic<bool> paused {false};
    std::atomic<bool> stoped {false};
};


#endif
