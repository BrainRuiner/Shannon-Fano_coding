#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <vector>
#include <iostream>
#include "BinarySearchTree.hpp"

namespace sfc
{
  struct SFCoding
  {
    void readCommands(std::istream& in, std::ostream& out);
    std::ostream& decode(std::istream& in, std::ostream& out);
    std::ostream& encode(std::istream& in, std::ostream& out);

    private:
    using bTree = bst::BinarySearchTree< char >;
    char* decode(char* dest, char* src, const bTree& codes);
    char* encode(char* dest, char* src, const bTree& codes);
    bTree& generateCodes(bTree& dest, char* src);
  };
}

#endif
