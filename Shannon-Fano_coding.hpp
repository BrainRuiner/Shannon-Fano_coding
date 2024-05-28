#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <iostream>
#include "BinarySearchTree.hpp"

namespace sfc
{
  struct SFCoding
  {
    void readCommands(std::istream& in, std::ostream& out);
    std::ostream& decode(std::istream& in, std::ostream& out);
    std::ostream& encode(std::istream& in, std::ostream& out);
    std::ostream& makeCodes(std::istream& in, std::ostream& out);

    private:
    utl::Node* codes;
    char decode(char src);
    char encode(char src);
    utl::Node* makeCodes(utl::Node* dest, const std::string& src);
    void FanosMethod(utl::Node* dest, size_t size);
  };
}

#endif
