#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include "DictionaryNode.hpp"

namespace codeWork{
  struct CodeNode{
    char key;
    size_t quantity;
    std::string code;
    CodeNode* right;
    CodeNode* left;
    CodeNode* parent;

    CodeNode(char k = 0, size_t q = 0, const std::string& c = "",
      CodeNode* r = nullptr, CodeNode* l = nullptr, CodeNode* p = nullptr);
    ~CodeNode();

    CodeNode& pushCode();
    CodeNode& pull(DictionaryNode& origin);
  };
  CodeNode* pushCodeArr(CodeNode* nodes, size_t size);
  CodeNode* pullArr(CodeNode* dest, DictionaryNode* origin, size_t size);
  //Connects nodes like they are list
  //DOES NOT COPY
  CodeNode* makeIntoList(CodeNode* nodes, size_t size);
  CodeNode* merge(CodeNode* first, CodeNode* second);
  CodeNode* mergeSort(CodeNode* list);
}

#endif
