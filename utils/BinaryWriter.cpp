#include "BinaryWriter.hpp"

namespace utils{
  BinaryWriter::BinaryWriter(): bitBuffer(0), currBit(0){}
  void BinaryWriter::write(std::ostream& out, std::istream& in,
    codeWork::CodeTree& codeTree){
    char inputCh = 0;
    std::string tmp = "";
    in >> std::noskipws;
    while (in >> inputCh){
      tmp = codeTree.findCode(inputCh);
      for (size_t i = 0; i < tmp.size(); ++i){
        writeBit(out, tmp[i]);
      }
    }
    flush(out);
  }
  void BinaryWriter::read(std::ostream& out, std::istream& in,
    codeWork::CodeTree& codeTree){
    char ch;
    std::string code;
    size_t maxCodeLength = codeTree.getMaxCodeLength();
    size_t minCodeLength = codeTree.getMinCodeLength();
    in >> std::noskipws;
    while (in >> ch){
      for (size_t i = 0; i < 8; ++i){
        code += readBitChar(ch);
        ch <<= 1;
        if (minCodeLength <= code.size()){
          try{
            out << codeTree.findKey(code);
            code = "";
          }
          catch (...){
          }
        }
      }
      if (maxCodeLength < code.size()){
        throw std::logic_error("NO CODE FOUND");
      }
    }
  }
  void BinaryWriter::flush(std::ostream& out){
    while (currBit){
      writeBit(out, 0);
    }
  }
  void BinaryWriter::writeBit(std::ostream& out, char bit){
    bitBuffer <<= 1;
    if (bit == '1')
      bitBuffer |= 0b1;
    ++currBit;
    if (currBit == 8){
      out << bitBuffer;
      currBit = 0;
      bitBuffer = 0;
    }
  }
  char BinaryWriter::readBitChar(char ch){
    char bit;
    if (ch & 0b10000000){
      bit = '1';
    }
    else{
      bit = '0';
    }
    return bit;
  }
}
