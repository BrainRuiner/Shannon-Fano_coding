#ifndef BIN_WRITER_HPP
#define BIN_WRITER_HPP

#include <iostream>
#include "../codeWork/Dictionary.hpp"

namespace utils{
  class BinaryWriter{
    public:
    BinaryWriter();
    void write(std::ostream& out, std::istream& in, codeWork::Dictionary& dict);
    void read(std::ostream& out, std::istream& in, codeWork::Dictionary& dict);

    void writeBit(std::ostream& out, char bit);
    char readBitChar(char ch);
    char reverseBits(char ch);
    void flush(std::ostream& out);
    private:
    char bitBuffer;
    size_t currBit;

  };
}

#endif
