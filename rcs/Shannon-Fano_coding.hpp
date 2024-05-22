#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <vector>
#include "BinarySearchTree.hpp"

namespace sfc
{
  struct SFCoding
  {
    SFCoding();
    SFCoding(std::string* files, bst::BinarySearchTree< char >* codes);
    SFCoding(const SFCoding& src) = delete;
    SFCoding(const SFCoding&& src) = delete;
    ~SFCoding();

    SFCoding& operator=(const SFCoding& src) = delete;
    SFCoding& operator=(const SFCoding&& src) = delete;

    char* encode(char* dest, char* src, const bst::BinarySearchTree< char >& codes);
    char* decode(char* dest, char* src, const bst::BinarySearchTree< char >& codes);

    bst::BinarySearchTree< char >& generateCodes(bst::BinarySearchTree< char >& dest, char* src);
  };
}

#endif
