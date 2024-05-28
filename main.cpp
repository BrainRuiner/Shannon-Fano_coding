#include <iostream>
#include "BinarySearchTree.hpp"
#include "utils.hpp"
#include "Shannon-Fano_coding.hpp"

int main()
{
  bst::BinarySearchTree< char > b;
  sfc::SFCoding s;
  std::string a = "ggg eee qqqq ee lll\n";
  s.makeCodes(b, a);


  return 0;
}
