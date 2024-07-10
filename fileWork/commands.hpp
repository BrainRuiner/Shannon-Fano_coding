#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <fstream>
#include <string>

namespace fileWork
{
  void runCommandLoop(std::ostream& out, std::istream& in);

  void readText
  (
    std::ostream& out,
    const std::string& text
  );
  void readBinary
  (
    std::ostream& out,
    const std::string& binary
  );
  void decode
  (
    std::ostream& out,
    std::istream& in,
    const std::string& binary,
    const std::string& codes = "codes.txt",
    const std::string& text = "text.txt"
  );
  void encode
  (
    std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& binary = "binary.bin",
    const std::string& codes = "codes.txt"
  );
  void makeCodes
  (
    std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& codes = "codes.txt"
  );
}

#endif
