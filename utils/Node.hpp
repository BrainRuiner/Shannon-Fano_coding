#ifndef NODE_HPP
#define NODE_HPP

#include <ostream>

namespace utils
{
  template <class T>
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
  template <class T>
  std::ostream& operator<<(std::ostream& out, const Node<T>& node)
  {
    return out << node.key;
  }
}

#endif
