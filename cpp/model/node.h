#ifndef NODE_H
#define NODE_H

enum class NodeType {
  Empty,
  Visited,
  Wall,
  Path,
  Start,
  End,
  WeightNode,
  InactivePath
};

struct Node {
  int weight = 0;
  // int parent = -1;
  NodeType type = NodeType::Empty;
};

#endif // NODE_H
