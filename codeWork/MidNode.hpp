#ifndef MID_NODE_HPP
#define MID_NODE_HPP

#include "../utils/Node.hpp"
#include "CodeNode.hpp"

namespace codeWork
{
  template < class T >
  struct MidNode: public utils::Node< T >
  {
    CodeNode< T >* nodes;
    size_t size;

    MidNode(CodeNode< T >* n, size_t s, const T& k = 0,
      CodeNode< T >* l = nullptr, CodeNode< T >* r = nullptr, CodeNode< T >* p = nullptr):
      utils::Node< T >::Node(k, l, r, p),
      nodes(n),
      size(s)
    {}

    void clearNode()
    {
      size = 0;
      nodes = nullptr;
    }
  };
  template < class T >
  std::ostream& operator<<(std::ostream& out, const MidNode< T >& node)
  {
    for (size_t i = 0; i < node.size; ++i)
    {
      out << node.nodes[i] << '\n';
    }
    return out;
  }
}

#endif
