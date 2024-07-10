#ifndef SFC_HPP
#define SFC_HPP

#include "../codeWork/DictionaryNode.hpp"
#include "../codeWork/CodeNode.hpp"

namespace sfc
{
  using DictNode = codeWork::DictionaryNode;
  using CodeNode = codeWork::CodeNode;
  DictNode* fillCodes(DictNode* nodes, size_t size);
  //Need a list
  void useSfcAlgo(CodeNode* list);
  CodeNode* divideAndZeros(CodeNode* list);
  size_t calcGlobCount(CodeNode* list);

  void print(CodeNode* list);
}

#endif
