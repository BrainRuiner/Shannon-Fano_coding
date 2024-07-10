#include <iostream>
#include "fileWork/commands.hpp"

int main()
{
  fileWork::readText(std::cout, "testData/text.txt");
  fileWork::readBinary(std::cout, "testData/bin.bin");
  return 0;
}
