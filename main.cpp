#include <iostream>
#include "codeWork/CodeNode.hpp"
#include "codeWork/SFCTree.hpp"
#include "codeWork/MidNode.hpp"

int main()
{
  using namespace codeWork;
  using namespace utils;

  size_t size = 5;
  CodeNode< char >* nodes = new CodeNode< char >[size]
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
  Node< char >** n = new Node< char >*[size];
  for (size_t i = 0; i < size; ++i)
  {
    n[i] = &nodes[i];
  }
  auto list = makeIntoList(n, size);
  print(std::cout, nodes, size);


  CodeNode< char >* curr = static_cast< CodeNode< char >* >(*list);
  while (curr->right)
  {
    std::cout << *curr << '\n';
    curr = curr->right;
  }
  std::cout << '\n';
  //SFCTree< char > t(nodes, size);

  return 0;
}
