#include "DictionaryNode.hpp"

namespace codeWork
{
  DictionaryNode::DictionaryNode(char k, size_t q, const std::string& c):
    key(k),
    quantity(q),
    code(c)
  {}

  std::ostream& operator<<(std::ostream& out, const DictionaryNode& node)
  {
    return out << node.key << " : " << node.code;
  }
  void print(std::ostream& out, const DictionaryNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i] << '\n';
    }
  }
}
