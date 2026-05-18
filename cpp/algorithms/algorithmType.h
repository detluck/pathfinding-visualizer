#ifndef ALGORITHMTYPE_H
#define ALGORITHMTYPE_H

enum class AlgorithmType{
    Dijkstra,
    Astar,
    Bfs,
    Count
};

enum class TspAlgorithmType{
    Bruteforce,
    Count
};

enum class StepResultType{
    Running,
    Paused,
    Finished
};

#endif // ALGORITHMTYPE_H
