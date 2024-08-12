#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <fstream>
#include <string>

namespace fileWork{
  void runCommandLoop(std::ostream& out, std::istream& in);
  template <class First, class ...Other>
  void runArgReader(std::istream& in, First& first, Other& ...other);
  void runArgReader(std::istream& in);

  void read(std::ostream& out, const std::string& file = "");
  void decode(std::ostream& out, const std::string& binary,
    const std::string& codes,
    const std::string& text = "");
  void encode(std::ostream& out, const std::string& text,
    const std::string& binary = "",
    const std::string& codes = "");
  void makeCodes(std::ostream& out, const std::string& text,
    const std::string& codes = "");

  std::string insert(char delimiter, const std::string& insert, const std::string& fileName);
}

#endif
