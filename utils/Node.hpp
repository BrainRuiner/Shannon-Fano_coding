#ifndef NODE_HPP
#define NODE_HPP

#include <ostream>
#include <string>

namespace utils
{
  struct Node
  {
    std::string code;

    Node* left;
    Node* right;
    Node* parent;

    Node(const std::string& c = "", Node* l = nullptr, Node* r = nullptr, Node* p = nullptr):
      code(c),
      left(l),
      right(r),
      parent(p)
    {}

    virtual char getKey()
    {
      return '\0';
    }
    std::string getCode()
    {
      return code;
    }
  };
  //Connects nodes like they are list
  //DOES NOT COPY
  Node** makeIntoList(Node** nodes, size_t size)
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      nodes[i]->right = nodes[i + 1];
    }
    return nodes;
  }
}

#endif
