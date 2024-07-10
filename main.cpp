#include <iostream>
#include "codeWork/CodeNode.hpp"
#include "sfc/SFC.hpp"

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

  CodeNode* wn = new CodeNode[size];
  pullArr(wn, nodes, size);
  print(std::cout, wn, size);
  CodeNode* list = makeIntoList(wn, size);
  print(std::cout, wn, size);
  sfc::useSfcAlgo(list);
  print(std::cout, wn, size);

  return 0;
}
