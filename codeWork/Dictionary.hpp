#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "DictionaryNode.hpp"

namespace codeWork{
  class Dictionary{
    public:
    Dictionary(std::istream& in, bool isCodeFile = false);
    Dictionary(const Dictionary&) = delete;
    Dictionary(Dictionary&&) = delete;
    ~Dictionary();

    Dictionary& operator=(const Dictionary&) = delete;
    Dictionary& operator=(Dictionary&&) = delete;

    void print(std::ostream& out);
    std::string findCode(char key);
    char findKey(const std::string& code);

    private:
    DictionaryNode* nodes;
    size_t size;

    void makeDictionary(std::istream& in);
    void readDictionary(std::istream& in);
  };
}

#endif
