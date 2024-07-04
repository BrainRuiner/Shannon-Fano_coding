#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>
#include "../utils/Node.hpp"

namespace codeWork
{
  template <class T>
  struct CodeNode: public utils::Node
  {
    T key;
    size_t quantity = 0;
    double frequency = 0;
    std::string code = "";

    CodeNode(const T& k = 0, size_t q = 0, double f = 0, const std::string& c = "",
      CodeNode* l = nullptr, CodeNode* r = nullptr, CodeNode* p = nullptr):
      key(k),
      quantity(q),
      frequency(f),
      code(c),
      Node(l, r, p)
    {}
  };
  template <class T>
  std::ostream& operator<<(std::ostream& out, const CodeNode<T>& node)
  {
    return out << node.key << " : " << node.quantity << " : " << node.frequency << node.code;
  }
}

#endif
