#include "CodeNode.hpp"

namespace codeWork
{
  CodeNode::CodeNode(char k, size_t q, DictionaryNode* o,
    const std::string& c, CodeNode* n, double f):
    DictionaryNode(k, q, c, f),
    origin(o),
    next(n)
  {}
  CodeNode::~CodeNode()
  {
    delete next;
  }
  CodeNode& CodeNode::pushCode()
  {
    origin->code = code;
    return *this;
  }
  CodeNode& CodeNode::pull(DictionaryNode& origin)
  {
    key = origin.key;
    quantity = origin.quantity;
    code = origin.code;
    frequency = origin.frequency;
    this->origin = &origin;
    return *this;
  }
  CodeNode* pushCodeArr(CodeNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      nodes[i].pushCode();
    }
    return nodes;
  }
  CodeNode* pullArr(CodeNode* dest, DictionaryNode* origin, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      dest[i].pull(origin[i]);
    }
    return dest;
  }
  CodeNode* makeIntoList(CodeNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      nodes[i].next = &nodes[i + 1];
    }
    return nodes;
  }
  void print(std::ostream& out, const CodeNode* nodes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i].key << ' ' << nodes[i].code << '\n';
    }
  }
}
