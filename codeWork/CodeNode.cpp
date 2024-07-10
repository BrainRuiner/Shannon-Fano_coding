#include "CodeNode.hpp"

namespace codeWork
{
  CodeNode::CodeNode(char k, size_t q, DictionaryNode* o,
    const std::string& c, CodeNode* n, double f):
    DictionaryNode(k, q, c, f),
    origin(o),
    next(n)
  {}
  //Pushes code to origin and deletes as list
  CodeNode::~CodeNode()
  {
    origin->code = code;
    delete next;
  }
  CodeNode& pull(CodeNode& dest, DictionaryNode& origin)
  {
    dest.key = origin.key;
    dest.quantity = origin.quantity;
    dest.code = origin.code;
    dest.frequency = origin.frequency;
    dest.origin = &origin;
    return dest;
  }
  CodeNode* pullArr(CodeNode* dest, DictionaryNode* origin, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      pull(dest[i], origin[i]);
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
