#ifndef BIN_WRITER_HPP
#define BIN_WRITER_HPP

#include <iostream>
#include "../codeWork/SFCTree.hpp"

namespace utils{
  class BinaryWriter{
    public:
    BinaryWriter();
    void write(std::ostream& out, std::istream& in, codeWork::SFCTree& codeTree);
    void read(std::ostream& out, std::istream& in, codeWork::SFCTree& codeTree);

    private:
    char bitBuffer;
    size_t currBit;

    void writeBit(std::ostream& out, char bit);
    char readBitChar(char ch);
    void flush(std::ostream& out);
  };
}

#endif
