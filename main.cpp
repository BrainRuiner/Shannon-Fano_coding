#include <iostream>
#include "fileWork/commands.hpp"
//#include "codeWork/DictionaryNode.hpp"
//#include "utils/BinaryWriter.hpp"
#include "codeWork/SFCTree.hpp"
#include <fstream>
#include <ctime>

int main(){
  // fileWork::readText(std::cout, "testData/text.txt");
  // fileWork::readBinary(std::cout, "testData/bin.bin");
  // fileWork::makeCodes(std::cout, "testData/text.txt", "testData/codes.txt");
  // fileWork::encode(std::cout, "testData/text.txt", "testData/binary.bin",
  //   "testData/codes.txt");
  // fileWork::decode(std::cout, "testData/binary.bin", "testData/codes.txt",
  //   "testData/res.txt");
  // //fileWork::runComma!in.eof()ndLoop(std::cout, std::cin);

  auto c1 = std::clock();
  fileWork::makeCodes(std::cout, "bigfile.txt", "bigCodes.txt");
  std::cout << "makeCodes: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::encode(std::cout, "bigfile.txt", "bigBinary.bin",
    "bigCodes.txt");
  std::cout << "encode: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::decode(std::cout, "bigBinary.bin", "bigCodes.txt",
    "bigRes.txt");
  //fileWork::runCommandLoop(std::cout, std::cin);
  std::cout << "decode: " << std::clock() - c1 << '\n';

  return 0;
}
