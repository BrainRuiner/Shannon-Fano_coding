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

void bookTest(){
  auto c1 = std::clock();
  fileWork::makeCodes(std::cout, "alice.txt", "aliceCodes.txt");
  std::cout << "makeCodes: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::encode(std::cout, "alice.txt", "aliceBinary.bin",
    "aliceCodes.txt");
  std::cout << "encode: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::decode(std::cout, "aliceBinary.bin", "aliceCodes.txt",
    "aliceRes.txt");
  std::cout << "decode: " << std::clock() - c1 << '\n';
}

void bookTest2(){
  auto c1 = std::clock();
  fileWork::makeCodes(std::cout, "mobyDick.txt", "mobyDickCodes.txt");
  std::cout << "makeCodes: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::encode(std::cout, "mobyDick.txt", "mobyDickBinary.bin",
    "mobyDickCodes.txt");
  std::cout << "encode: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::decode(std::cout, "mobyDickBinary.bin", "mobyDickCodes.txt",
    "mobyDickRes.txt");
  std::cout << "decode: " << std::clock() - c1 << '\n';
}

int main(){
  //bigTest();
  bookTest();
  bookTest2();
  // fileWork::runCommandLoop(std::cout, std::cin);
  return 0;
}
