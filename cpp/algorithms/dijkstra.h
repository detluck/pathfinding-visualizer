#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "ialgorithm.h"
#include <atomic>

class Dijkstra: public IAlgorithm
{
public:
    ~Dijkstra() override = default;
    void run(const GridData& data) override;
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
