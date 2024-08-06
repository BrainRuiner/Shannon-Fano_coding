#ifndef BIN_WRITER_HPP
#define BIN_WRITER_HPP

#include <iostream>
//#include "../codeWork/Dictionary.hpp"
#include "../codeWork/SFCTree.hpp"

namespace utils{
  class BinaryWriter{
    public:
    BinaryWriter();
    void write(std::ostream& out, std::istream& in, codeWork::SFCTree& codeTree);
    void read(std::ostream& out, std::istream& in, codeWork::SFCTree& codeTree);

    void writeBit(std::ostream& out, char bit);
    char readBitChar(char ch);
    void flush(std::ostream& out);
    private:
    char bitBuffer;
    size_t currBit;

  };
}

#endif
