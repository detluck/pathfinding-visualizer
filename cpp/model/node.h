#ifndef NODE_H
#define NODE_H
#include <climits>

enum class NodeType{
    Empty,
    Visited,
    Wall,
    Path,
    Start,
    End
};

struct Node{
    int distance = INT_MAX;
    int parent = -1;

    NodeType type = NodeType::Empty;
};

#endif // NODE_H
