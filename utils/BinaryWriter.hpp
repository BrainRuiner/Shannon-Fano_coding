#ifndef BIN_WRITER_HPP
#define BIN_WRITER_HPP

#include <iostream>
#include "../codeWork/CodeTree.hpp"

namespace utils{
  class BinaryWriter{
    public:
    BinaryWriter();
    void write(std::ostream& out, std::istream& in, codeWork::CodeTree& codeTree);
    void read(std::ostream& out, std::istream& in, codeWork::CodeTree& codeTree);

    private:
    char bitBuffer;
    size_t currBit;

    void flush(std::ostream& out);
    void writeBit(std::ostream& out, char bit);
    char readBitChar(char ch);
  };
}

#endif
