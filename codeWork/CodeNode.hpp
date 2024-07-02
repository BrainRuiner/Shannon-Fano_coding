#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>

namespace codeWork
{
  template <class T>
  struct CodeNode
  {
    T key;
    size_t quantity = 0;
    std::string code = "";

    CodeNode* left;
    CodeNode* right;
    CodeNode* parent;
    CodeNode(const T& k, size_t q, const std::string& c,
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      key(k),
      quantity(q),
      code(c),
      left(l),
      right(r),
      parent(p)
    {}
  };
}

#endif
