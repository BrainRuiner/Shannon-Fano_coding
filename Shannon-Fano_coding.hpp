#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <iostream>
#include "utils.hpp"

namespace sfc
{
  struct SFCoding
  {
    void readCommands(std::istream& in, std::ostream& out);
    void decode(std::istream& in);
    void encode(std::istream& in);
    void autoCodes(std::istream& in);

    private:
    utl::Node* codes_ = nullptr;
    size_t size_ = 0;

    char decode(const std::string& src);
    std::string encode(char src);
    utl::Node* autoCodes(utl::Node* dest, size_t& size, const std::string& src);
    void FanosMethod(utl::Node* dest, size_t size);
  };
}

#endif
