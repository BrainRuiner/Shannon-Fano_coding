#include <iostream>
#include "fileWork/commands.hpp"
#include "codeWork/DictionaryNode.hpp"
#include "utils/BinaryWriter.hpp"

int main(){
  fileWork::readText(std::cout, "testData/text.txt");
  fileWork::readBinary(std::cout, "testData/bin.bin");
  fileWork::makeCodes(std::cout, "testData/text.txt", "testData/codes.txt");
  fileWork::encode(std::cout, "testData/text.txt", "testData/binary.bin",
    "testData/codes.txt");
  fileWork::decode(std::cout, "testData/binary.bin", "testData/codes.txt",
    "testData/res.txt");
  //fileWork::runCommandLoop(std::cout, std::cin);

  // std::ofstream fout("text.bin", std::ios::binary);
  // utils::BinaryWriter b;
  // char c[13] = {
  //   0,1,0,0,
  //   0,0,0,1,
  //   0,1,0,0,
  //   0
  // };
  // for (size_t i = 0; i < 13; ++i){
  //   b.writeBit(fout, c[i]);
  // }
  // b.flush(fout);
  // fout.close();

  // std::ifstream fin("text.bin");
  // char ch;
  // std::string code;
  // while (fin >> ch){
  //   std::cout << ch;
  //   for (size_t i = 0; i < 8; ++i){
  //     code += b.readBitChar(ch);
  //     ch <<= 1;
  //   }
  // }
  // std::cout << '\n';
  // std::cout << code << '\n';

  // fin.close();
  return 0;
}
