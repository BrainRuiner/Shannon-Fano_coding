#ifndef DICTIONARY_NODE_HPP
#define DICTIONARY_NODE_HPP

#include <string>

namespace codeWork
{
  struct DictionaryNode
  {
    char key;
    size_t quantity;
    std::string code;
    double frequency;

    DictionaryNode(char k = 0, size_t q = 0, const std::string& c = "", double f = 0);
  };
  std::ostream& operator<<(std::ostream& out, const DictionaryNode& node);
  DictionaryNode* calcFreq(DictionaryNode* nodes, size_t size);
  void print(std::ostream& out, const DictionaryNode* nodes, size_t size);
}

#endif
