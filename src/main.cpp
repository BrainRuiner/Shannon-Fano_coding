#include <iostream>
#include <ctime>
#include "fileWork/commands.hpp"

void speedTest(const std::string& path, const std::string& file){
  std::cout << path + file << '\n';
  auto c1 = std::clock();
  fileWork::makeCodes(std::cout, path + file);
  std::cout << "makeCodes: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::encode(std::cout, path + file);
  std::cout << "encode: " << std::clock() - c1 << '\n';
  c1 = std::clock();
  fileWork::decode(std::cout, path + "binary" + file, path + "codes" + file);
  std::cout << "decode: " << std::clock() - c1 << '\n';
}

int main(){
  speedTest("./testData/", "bigfile.txt");
  speedTest("./testData/books/", "alice.txt");
  //speedTest("./testData/books/", "book-war-and-peace.txt");
  //fileWork::runCommandLoop(std::cout, std::cin);
  return 0;
}
