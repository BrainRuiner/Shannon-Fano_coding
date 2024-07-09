#include "DictionaryNode.hpp"
#include "iostream"

namespace codeWork
{
  DictionaryNode::DictionaryNode(char k, size_t q, const std::string& c, double f):
    key(k),
    quantity(q),
    code(c),
    frequency(f)
  {}

  std::ostream& operator<<(std::ostream& out, const DictionaryNode& node)
  {
    return out << node.key << " : " << node.code;
  }
  DictionaryNode* calcFreq(DictionaryNode* nodes, size_t size)
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
  void print(std::ostream& out, const DictionaryNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i] << '\n';
    }
  }
}
