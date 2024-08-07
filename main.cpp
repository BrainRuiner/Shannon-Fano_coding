#include <iostream>
#include "fileWork/commands.hpp"
//#include "codeWork/DictionaryNode.hpp"
//#include "utils/BinaryWriter.hpp"
#include "codeWork/CodeTree.hpp"
#include <fstream>
#include <ctime>

void bigTest(){
  auto c1 = std::clock();
  fileWork::makeCodes(std::cout, "bigfile2.txt", "bigCodes.txt");
  std::cout << "makeCodes: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::encode(std::cout, "bigfile2.txt", "bigBinary.bin",
    "bigCodes.txt");
  std::cout << "encode: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::decode(std::cout, "bigBinary.bin", "bigCodes.txt",
    "bigRes.txt");
  std::cout << "decode: " << std::clock() - c1 << '\n';
}

int main(){
  bigTest();
  // fileWork::runCommandLoop(std::cout, std::cin);
  return 0;
}
