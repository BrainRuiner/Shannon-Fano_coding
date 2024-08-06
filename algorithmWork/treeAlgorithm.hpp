#ifndef SFC_HPP
#define SFC_HPP

#include "../codeWork/CodeNode.hpp"

namespace awk{
  namespace cwk = codeWork;

  void listToTree(cwk::CodeNode* list);
  cwk::CodeNode* divideAndZeros(cwk::CodeNode* list);
  size_t calcGlobCount(cwk::CodeNode* list);
}

#endif
