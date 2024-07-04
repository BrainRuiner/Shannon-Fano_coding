#include <iostream>
#include "codeWork/CodeNode.hpp"
#include "codeWork/SFCTree.hpp"
#include "codeWork/MidNode.hpp"

int main()
{
  using namespace codeWork;
  CodeNode<char>* nodes = new CodeNode<char>[5]
    {
      { 'a', 15 },
      { 'b', 7 },
      { 'c', 6 },
      { 'd', 6 },
      { 'e', 5 }
    };
  size_t size = 5;
  size_t count = 0;
  for (size_t i = 0; i < size; ++i)
  {
    count += nodes[i].quantity;
  }
  for (size_t i = 0; i < size; ++i)
  {
    nodes[i].frequency = static_cast< double >(nodes[i].quantity) / count;
    std::cout << nodes[i] << '\n';
  }
  SFCTree<char> t(nodes, size);

  return 0;
}
