#ifndef NODE_HPP
#define NODE_HPP

#include <ostream>

namespace utils
{
  template < class T >
  struct Node
  {
    T key;

    Node* left;
    Node* right;
    Node* parent;

    Node(const T& k = 0, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr):
      key(k),
      left(l),
      right(r),
      parent(p)
    {}
  };
  template < class T >
  std::ostream& operator<<(std::ostream& out, const Node< T >& node)
  {
    return out << node.key;
  }
  //Connects nodes like they are list
  //DOES NOT COPY
  template < class T >
  Node< T >** makeIntoList(Node< T >** nodes, size_t size)
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      nodes[i]->right = nodes[i + 1];
    }
    return nodes;
  }
}

#endif
