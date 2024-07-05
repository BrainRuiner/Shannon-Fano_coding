#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>
#include "../utils/Node.hpp"

namespace codeWork
{
  struct CodeNode: public utils::Node
  {
    char key;
    size_t quantity;
    double frequency;

    CodeNode(char k = 0, size_t q = 0, double f = 0, const std::string& c = "",
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      Node::Node(c, l, r, p),
      key(k),
      quantity(q),
      frequency(f)
    {}

    char getKey()
    {
      return key;
    }
  };
  std::ostream& operator<<(std::ostream& out, const CodeNode& node)
  {
    return out << node.key << " : " << node.quantity << " : " << node.frequency << node.code;
  }
  CodeNode* calcFreq(CodeNode* nodes, size_t size)
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
  void print(std::ostream& out, const CodeNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i] << '\n';
    }
  }
}

#endif
