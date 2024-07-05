#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>

namespace codeWork
{
  struct CodeNode
  {
    char key;
    size_t quantity;
    double frequency;
    std::string code;

    CodeNode* left;
    CodeNode* right;
    CodeNode* parent;

    CodeNode(char k = 0, size_t q = 0, double f = 0, const std::string& c = "",
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      key(k),
      quantity(q),
      frequency(f),
      code(c),
      left(l),
      right(r),
      parent(p)
    {}
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
  //Connects nodes like they are list
  //DOES NOT COPY
  CodeNode* makeIntoList(CodeNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      nodes[i].right = &nodes[i + 1];
    }
    return nodes;
  }
}

#endif
