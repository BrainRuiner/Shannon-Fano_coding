#include <iostream>
#include "sfc/SFC.hpp"
#include "utils/quickSort.hpp"

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

  utils::quickSort(nodes, size,
    [](const DictionaryNode& a, const DictionaryNode& b)
    {
      return a.quantity > b.quantity;
    });
  sfc::fillCodes(nodes, size);
  print(std::cout, nodes, size);
  return 0;
}
