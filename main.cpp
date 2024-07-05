#include <iostream>
#include "codeWork/CodeNode.hpp"
#include "codeWork/SFCTree.hpp"

int main()
{
  using namespace codeWork;
  using namespace utils;

  size_t size = 5;
  CodeNode* nodes = new CodeNode[size]
  {
    { 'a', 15 },
    { 'b', 7 },
    { 'c', 6 },
    { 'd', 6 },
    { 'e', 5 }
  };

  calcFreq(nodes, size);
  print(std::cout, nodes, size);
  std::cout << "===================================\n";
  auto list = makeIntoList(nodes, size);
  print(std::cout, nodes, size);


  // CodeNode* curr = static_cast< CodeNode* >(*list);
  // while (curr->right)
  // {
  //   std::cout << *curr << '\n';
  //   curr = curr->right;
  // }
  std::cout << '\n';
  //SFCTree t(nodes, size);

  return 0;
}
