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
    using bTree = bst::BinarySearchTree< char >;
    const std::string& decode(const std::string& dest, const std::string& src, const bTree& codes);
    const std::string& encode(const std::string& dest, const std::string& src, const bTree& codes);
    bTree& makeCodes(bTree& dest, const std::string& src);
  };
}

#endif
