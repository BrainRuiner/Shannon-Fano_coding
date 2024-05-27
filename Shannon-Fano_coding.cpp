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
// char* decode(char* dest, char* src, const bTree& codes);
// char* encode(char* dest, char* src, const bTree& codes);
sfc::SFCoding::bTree& sfc::SFCoding::makeCodes(bTree& dest, const std::string& src)
{
  using namespace utl;
  std::string alph = "abcdefghijklmnopqrstuvwxyz0123456789 \n";
  size_t alphLen = alph.size();
  Node* set = new Node[alphLen];
  for (size_t i = 0; i < alphLen; ++i)
  {
    set[i].symbol = alph[i];
  }
  for (size_t i = 0; i < src.size(); ++i)
  {
    for (size_t j = 0; j < alphLen; ++j)
    {
      if (set[j].symbol == src[i])
      {
        ++set[j].quantity;
      }
    }
  }
  sortByQuantity(set, alphLen);
  delete[] set;
  return dest;
}
