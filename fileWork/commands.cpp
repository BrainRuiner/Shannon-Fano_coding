#include "commands.hpp"
#include <fstream>
#include <string>
#include "../codeWork/DictionaryNode.hpp"

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
    const std::string& binary,
    const std::string& codes,
    const std::string& text)
  {

  }
  //В бинарные файлы нужно по особому записывать
  //Группируя по октавам. Не забудь переделать
  void encode(std::ostream& out,
    const std::string& text,
    const std::string& binary,
    const std::string& code)
  {
    try
    {
      std::ifstream fin(text, std::ios::in);
      size_t size = 0;
      codeWork::DictionaryNode* dict = nullptr;
      if (code == "")
      {
        dict = codeWork::makeDictionary(fin, size);
      }
      else
      {
        std::ifstream finCode(code, std::ios::in);
        dict = codeWork::readDictionary(finCode, size, dict);
        finCode.close();
      }
      std::ofstream fout(binary, std::ios::out | std::ios::binary);
      char inputCh = 0;
      std::string tmp = "";
      fin.clear();
      fin.seekg(0);
      fin >> std::noskipws;
      while (!fin.eof())
      {
        fin >> inputCh;
        tmp = codeWork::findCode(inputCh, dict, size);
        out << tmp;
        fout << tmp;
      }
      fout.close();
      fin.close();
    }
    catch (...)
    {
      throw;
    }
  }
  void makeCodes(std::ostream& out,
    const std::string& text,
    const std::string& codes)
  {
    std::ifstream fin(text, std::ios::in);
    size_t size = 0;
    codeWork::DictionaryNode* dict = codeWork::makeDictionary(fin, size);
    fin.close();
    codeWork::print(out, dict, size);
    std::ofstream fout(codes, std::ios::out);
    codeWork::print(fout, dict, size);
    fout.close();
  }
}
