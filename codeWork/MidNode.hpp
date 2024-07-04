#ifndef MID_NODE_HPP
#define MID_NODE_HPP

#include "../utils/Node.hpp"
#include "CodeNode.hpp"

namespace codeWork
{
  template <class T>
  struct MidNode: public utils::Node
  {
    CodeNode<T>* nodes;
    size_t size;

    CodeNode<T>* left;
    CodeNode<T>* right;
    CodeNode<T>* parent;

    MidNode(CodeNode<T>* n, size_t s,
      CodeNode<T>* l = nullptr, CodeNode<T>* r = nullptr, CodeNode<T>* p = nullptr):
      nodes(n),
      size(s),
      Node(l, r, p)
    {}
  };
  template <class T>
  std::ostream& operator<<(std::ostream& out, const MidNode<T>& node)
  {
    for (size_t i = 0; i < node.size; ++i)
    {
      out << node.nodes[i] << '\n';
    }
    return out;
  }
}

#endif
