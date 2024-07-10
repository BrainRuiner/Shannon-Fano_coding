#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <string>
#include <ostream>
#include "DictionaryNode.hpp"

namespace codeWork
{
  struct CodeNode: public DictionaryNode
  {
    DictionaryNode* origin;
    CodeNode* next;

    CodeNode(char k = 0, size_t q = 0, DictionaryNode* o = nullptr,
      const std::string& c = "", CodeNode* n = nullptr, double f = 0);
    ~CodeNode();
  };
  CodeNode& pull(CodeNode& dest, const DictionaryNode& origin);
  CodeNode* pullArr(CodeNode* dest, DictionaryNode* origin, size_t size);
  //Connects nodes like they are list
  //DOES NOT COPY
  CodeNode* makeIntoList(CodeNode* nodes, size_t size);
  void print(std::ostream& out, const CodeNode* nodes, size_t size);
}

#endif
