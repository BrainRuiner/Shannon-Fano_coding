#include <iostream>
//#include "fileWork/commands.hpp"
//#include "codeWork/DictionaryNode.hpp"
//#include "utils/BinaryWriter.hpp"
#include "codeWork/SFCTree.hpp"
#include <fstream>

int main(){
  // fileWork::readText(std::cout, "testData/text.txt");
  // fileWork::readBinary(std::cout, "testData/bin.bin");
  // fileWork::makeCodes(std::cout, "testData/text.txt", "testData/codes.txt");
  // fileWork::encode(std::cout, "testData/text.txt", "testData/binary.bin",
  //   "testData/codes.txt");
  // fileWork::decode(std::cout, "testData/binary.bin", "testData/codes.txt",
  //   "testData/res.txt");
  // //fileWork::runComma!in.eof()ndLoop(std::cout, std::cin);


  // fileWork::makeCodes(std::cout, "bigfile2.txt", "bigCodes.txt");
  // fileWork::encode(std::cout, "bigfile2.txt", "bigBinary.bin",
  //   "bigCodes.txt");
  // std::cout << "Decode\n";
  // fileWork::decode(std::cout, "bigBinary.bin", "bigCodes.txt",
  //   "bigRes.txt");
  //fileWork::runCommandLoop(std::cout, std::cin);

  std::ifstream f("z.txt");
  codeWork::SFCTree tree(f, true);
  tree.print(std::cout);
  // codeWork::CodeNode tmp;
  // f >> std::noskipws;
  // while (!f.eof()){
  //   f >> tmp;
  //   std::cout << tmp.key << ' ' << tmp.code << '\n';
  //   //std::cout << f.peek() << f.eof() << '\n';

  // }
  f.close();

  return 0;
}
