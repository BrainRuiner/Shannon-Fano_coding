#ifndef SFC_HPP
#define SFC_HPP

#include "../codeWork/CodeNode.hpp"

namespace sfc{
  using DictNode = codeWork::DictionaryNode;
  using CodeNode = codeWork::CodeNode;

  DictNode* fillCodes(DictNode* nodes, size_t size);
  void useSfcAlgo(CodeNode* list);
  CodeNode* divideAndZeros(CodeNode* list);
  size_t calcGlobCount(CodeNode* list);
  CodeNode* checkAndSort(CodeNode* nodes, size_t size);
}

#endif
