#include <iostream>
#include "codeWork/CodeNode.hpp"
//#include "codeWork/SFCTree.hpp"

int main()
{
  using namespace codeWork;

  size_t size = 5;
  DictionaryNode* nodes = new DictionaryNode[size]
  {
    { 'a', 15 },
    { 'b', 7 },
    { 'c', 6 },
    { 'd', 6 },
    { 'e', 5 }
  };

  calcFreq(nodes, size);
  print(std::cout, nodes, size);

  CodeNode* wn = new CodeNode[size];
  fill(wn, nodes, size);
  print(std::cout, wn, size);
  std::cout << "===================================\n";
  auto list = makeIntoList(wn, size);
  print(std::cout, wn, size);

  CodeNode* curr = list;
  while (curr)
  {
    std::cout << curr->key << '\n';
    curr->origin->code = "101";
    curr = curr->next;
  }
  print(std::cout, nodes, size);
  std::cout << '\n';

  return 0;
}
