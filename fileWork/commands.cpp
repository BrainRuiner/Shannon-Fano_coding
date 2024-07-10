#include "commands.hpp"
#include <fstream>
#include <string>

namespace fileWork
{
  void runCommandLoop(std::ostream& out, std::istream& in)
  {}
  void readText(std::ostream& out,
    std::istream& in,
    const std::string& text)
  {
    std::ifstream fin(text, std::ios::in);


  }
  void readBinary(std::ostream& out,
    std::istream& in,
    const std::string& binary)
  {}
  void decode(std::ostream& out,
    std::istream& in,
    const std::string& binary,
    const std::string& codes = "codes.txt",
    const std::string& text = "text.txt")
  {

  }
  void encode(std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& binary = "binary.bin",
    const std::string& codes = "codes.txt")
  {}
  void makeCodes(std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& codes = "codes.txt")
  {}
}
