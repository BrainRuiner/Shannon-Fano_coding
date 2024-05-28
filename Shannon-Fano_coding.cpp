#include "Shannon-Fano_coding.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "utils.hpp"

void sfc::SFCoding::readCommands(std::istream& in, std::ostream& out)
{
  out << "> ";
  std::string cmd;
  while (in >> cmd)
  {
    try
    {
      if (cmd == "decode")
      {
        decode(in);
      }
      else if (cmd == "encode")
      {
        encode(in);
      }
      else if (cmd == "autoCodes")
      {
        autoCodes(in);
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }
    catch (const std::logic_error& e)
    {
      out << e.what() << '\n';
    }
    out << "\n> ";
  }
}
void sfc::SFCoding::decode(std::istream& in)
{
  std::string bin, text;
  in >> bin >> text;
  std::ifstream fin(bin, std::ios::in | std::ios::binary);
  std::ofstream fout(text, std::ios::out);
  char ch;
  std::string binary = "";
  while (fin >> ch)
  {
    binary += ch;
    ch = decode(binary);
    if (ch != '\0')
    {
      fout << ch;
      binary = "";
    }
  }
  if (binary != "")
  {
    fout.close();
    fin.close();
    throw std::logic_error("<NOT ENOUGH CODES>");
  }
  fout.close();
  fin.close();
}
void sfc::SFCoding::encode(std::istream& in)
{
  std::string text, bin;
  in >> text >> bin;
  std::ifstream fin(text, std::ios::in);
  std::ofstream fout(bin, std::ios::out | std::ios::binary);
  char ch;
  fin >> std::noskipws;
  try
  {
    while (fin >> ch)
    {
      fout << encode(ch);
    }
  }
  catch (...)
  {
    fout.close();
    fin.close();
    throw;
  }
  fout.close();
  fin.close();
}
void sfc::SFCoding::autoCodes(std::istream& in)
{
  std::string text;
  in >> text;
  std::ifstream fin(text, std::ios::in);
  fin.seekg(0, std::ios::end);
  size_t size = fin.tellg();
  std::string buffer(size, '\0');
  fin.seekg(0);
  fin.read(&buffer[0], size);

  codes_ = autoCodes(codes_, size_, buffer);
}
char sfc::SFCoding::decode(const std::string& src)
{
  for (size_t i = 0; i < size_; ++i)
  {
    if (src == codes_[i].code)
    {
      return codes_[i].symbol;
    }
  }
  return '\0';
}
std::string sfc::SFCoding::encode(char src)
{
  for (size_t i = 0; i < size_; ++i)
  {
    if (src == codes_[i].symbol)
    {
      return codes_[i].code;
    }
  }
  throw std::logic_error("<NOT ENOUGH CODES>");
}
utl::Node* sfc::SFCoding::autoCodes(utl::Node* dest, size_t& size, const std::string& src)
{
  using namespace utl;
  getNode(dest, size, src);
  FanosMethod(dest, size);
  return dest;
}
void sfc::SFCoding::FanosMethod(utl::Node* dest, size_t size)
{
  using namespace utl;
  if (size < 2)
  {
    return;
  }

  size_t size1 = size / 2;
  Node* arr1 = dest;
  size_t size2 = size - size1;
  Node* arr2 = &dest[size1];

  for (size_t i = 0; i < size1; ++i)
  {
    arr1[i].code += '1';
  }
  for (size_t i = 0; i < size2; ++i)
  {
    arr2[i].code += '0';
  }

  FanosMethod(arr1, size1);
  FanosMethod(arr2, size2);
}
