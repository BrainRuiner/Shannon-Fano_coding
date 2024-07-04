#ifndef NODE_HPP
#define NODE_HPP

namespace utils
{
  struct Node
  {
    Node* left;
    Node* right;
    Node* parent;

    Node(Node* l = nullptr, Node* r = nullptr, Node* p = nullptr):
      left(l),
      right(r),
      parent(p)
    {}
  };
}

#endif
