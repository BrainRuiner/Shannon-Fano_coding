#ifndef SFC_HPP
#define SFC_HPP

#include "../codeWork/CodeNode.hpp"

namespace sfc{
  using CodeNode = codeWork::CodeNode;

  void useSfcAlgo(CodeNode* list);
  CodeNode* divideAndZeros(CodeNode* list);
  size_t calcGlobCount(CodeNode* list);
}

#endif
