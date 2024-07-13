#include <iostream>
#include "fileWork/commands.hpp"
#include "codeWork/DictionaryNode.hpp"

int main(){
  fileWork::readText(std::cout, "testData/text.txt");
  fileWork::readBinary(std::cout, "testData/bin.bin");
  fileWork::makeCodes(std::cout, "testData/text.txt", "testData/codes.txt");
  fileWork::encode(std::cout, "testData/text.txt", "testData/binary.bin",
    "testData/codes.txt");
  fileWork::decode(std::cout, "testData/binary.bin", "testData/codes.txt",
    "testData/res.txt");
  return 0;
}
