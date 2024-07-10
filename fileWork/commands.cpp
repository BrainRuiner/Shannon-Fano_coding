#include "commands.hpp"
#include <fstream>
#include <string>

namespace fileWork
{
  void runCommandLoop(std::ostream& out, std::istream& in)
  {}
  void readText(std::ostream& out,
    const std::string& text)
  {
    try
    {
      std::ifstream fin(text, std::ios::in);
      char a = 0;
      fin >> std::noskipws;
      while (!fin.eof())
      {
        fin >> a;
        out << a;
      }
      fin.close();
    }
    catch (...)
    {
      throw std::logic_error("<WRONG FILE NAME>");
    }
  }
  void readBinary(std::ostream& out,
    const std::string& binary)
  {
    try
    {
      std::ifstream fin(binary, std::ios::binary | std::ios::ate);
      auto size = fin.tellg();
      std::string str(size, '\0');
      fin.seekg(0);
      if (fin.read(&str[0], size))
      {
        out << str << '\n';
      }
      fin.close();
    }
    catch (...)
    {
      throw std::logic_error("<WRONG FILE NAME>");
    }
  }
  void decode(std::ostream& out,
    std::istream& in,
    const std::string& binary,
    const std::string& codes,
    const std::string& text)
  {

  }
  void encode(std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& binary,
    const std::string& code)
  {}
  void makeCodes(std::ostream& out,
    std::istream& in,
    const std::string& text,
    const std::string& codes)
  {}
}
