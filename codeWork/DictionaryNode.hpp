#ifndef DICTIONARY_NODE_HPP
#define DICTIONARY_NODE_HPP

#include <string>
#include <iostream>

namespace codeWork
{
  struct DictionaryNode
  {
    char key;
    size_t quantity;
    std::string code;

    DictionaryNode
    (
      char k = 0,
      size_t q = 0,
      const std::string& c = ""
    );
  };
  std::ostream& operator<<(std::ostream& out, const DictionaryNode& node);
  void print
  (
    std::ostream& out,
    const DictionaryNode* nodes,
    size_t size
  );
}

#endif
