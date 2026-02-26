#ifndef IALGORITHM_H
#define IALGORITHM_H

class IAlgorithm{
public:
    virtual ~IAlgorithm() = default;
    virtual void run() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;

    virtual bool isRunning() const = 0;
};

#endif // IALGORITHM_H
