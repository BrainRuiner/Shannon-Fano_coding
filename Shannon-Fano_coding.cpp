#include "Shannon-Fano_coding.hpp"
#include <string>
#include "utils.hpp"

// void sfc::SFCoding::readCommands(std::istream& in, std::ostream& out)
// {
//   out << "> ";
//   std::string cmd;
//   while (in >> cmd)
//   {
//     if (cmd == "decode")
//     {
//       out << decode(in, out) << '\n';
//     }
//     else if (cmd == "encode")
//     {
//       out << encode(in, out) << '\n';
//     }
//     else if (cmd == "makeCodes")
//     {
//       out << makeCodes(in, out) << '\n';
//     }
//     else
//     {
//       out << "<INVALID COMMAND>\n";
//     }
//     out << "\n> ";
//   }
// }
// std::ostream& decode(std::istream& in, std::ostream& out)
// {

// }
// std::ostream& encode(std::istream& in, std::ostream& out);
char decode(char src);
char encode(char src);
utl::Node* sfc::SFCoding::makeCodes(utl::Node* dest, const std::string& src)
{
  using namespace utl;
  size_t size = 0;
  Node* set = nullptr;
  getNode(set, size, src);
  FanosMethod(set, size);
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
  Node* arr1 = new Node[size1];
  arr1 = dest;
  size_t size2 = size - size1;
  Node* arr2 = new Node[size2];
  arr2 = &dest[size1];

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
  delete[] arr1;
  delete[] arr2;
}
