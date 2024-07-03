#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <iostream>
#include "../utils/utils.hpp"

namespace sfc
{
  class SFCoding
  {
    public:
    SFCoding();
    SFCoding(const SFCoding&) = delete;
    SFCoding(SFCoding&&) = delete;
    ~SFCoding();

    SFCoding& operator=(const SFCoding&) = delete;
    SFCoding& operator=(SFCoding&&) = delete;

    void readCommands(std::istream& in, std::ostream& out);
    void decode(std::istream& in);
    void encode(std::istream& in);
    void autoCodes(std::istream& in);

    private:

    utl::Node* codes_;
    size_t size_ = 0;

    char decode(const std::string& src);
    std::string encode(char src);
    utl::Node* autoCodes(utl::Node* dest, size_t& size, const std::string& src);
    void FanosMethod(utl::Node* dest, size_t size);
  };
}

#endif
