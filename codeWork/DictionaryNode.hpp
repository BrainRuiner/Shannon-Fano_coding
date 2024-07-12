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
  std::istream& operator>>(std::istream& in, DictionaryNode& node);
  DictionaryNode* makeDictionary
  (
    std::istream& in,
    size_t& size,
    DictionaryNode* nodes = nullptr
  );
  DictionaryNode* readDictionary
  (
    std::istream& in,
    size_t& size,
    DictionaryNode* nodes = nullptr
  );
  void print
  (
    std::ostream& out,
    const DictionaryNode* nodes,
    size_t size
  );
  std::string findCode
  (
    char key,
    const DictionaryNode* nodes,
    size_t size
  );
  char findKey
  (
    std::string code,
    const DictionaryNode* nodes,
    size_t size
  );
}

#endif
