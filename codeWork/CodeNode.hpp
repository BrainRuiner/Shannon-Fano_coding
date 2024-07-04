#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>
#include "../utils/Node.hpp"

namespace codeWork
{
  template < class T >
  struct CodeNode: public utils::Node< T >
  {
    size_t quantity;
    double frequency;
    std::string code;

    CodeNode(const T& k = 0, size_t q = 0, double f = 0, const std::string& c = "",
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      utils::Node< T >::Node(k, l, r, p),
      quantity(q),
      frequency(f),
      code(c)
    {}
  };
  template < class T >
  std::ostream& operator<<(std::ostream& out, const CodeNode< T >& node)
  {
    return out << node.key << " : " << node.quantity << " : " << node.frequency << node.code;
  }
  template < class T >
  CodeNode< T >* calcFreq(CodeNode< T >* nodes, size_t size)
  {
    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
    {
      count += nodes[i].quantity;
    }
    for (size_t i = 0; i < size; ++i)
    {
      nodes[i].frequency = static_cast< double >(nodes[i].quantity) / count;
    }
    return nodes;
  }
  template < class T >
  void print(std::ostream& out, const CodeNode< T >* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i] << '\n';
    }
  }
}

#endif
