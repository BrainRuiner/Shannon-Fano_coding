#include <iostream>
#include "Shannon-Fano_coding.hpp"

int main()
{
  sfc::SFCoding a;
  a.readCommands(std::cin, std::cout);
  return 0;
}
