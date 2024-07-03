#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>

namespace codeWork
{
  template <class T>
  struct CodeNode
  {
    T key;
    size_t count = 0;
    std::string code = "";

    CodeNode* left;
    CodeNode* right;
    CodeNode* parent;

    CodeNode(const T& k, size_t q = 0, const std::string& c = "",
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      key(k),
      quantity(q),
      code(c),
      left(l),
      right(r),
      parent(p)
    {}
  };
  template <class T>
  std::ostream& operator<<(std::ostream& out, const CodeNode<T>& node)
  {
    return out << node.key << " : " << node.quantity << " : " << node.code;
  }
}

#endif
