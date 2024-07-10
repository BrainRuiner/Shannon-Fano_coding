#include <iostream>
#include "codeWork/CodeNode.hpp"
#include "sfc/SFC.hpp"

int main()
{
  using namespace codeWork;

  size_t size = 5;
  DictionaryNode* nodes = new DictionaryNode[size]
  {
    { 'b', 7 },
    { 'a', 15 },
    { 'e', 5 },
    { 'c', 6 },
    { 'd', 6 }
  };

  sfc::fillCodes(nodes, size);
  print(std::cout, nodes, size);
  return 0;
}
