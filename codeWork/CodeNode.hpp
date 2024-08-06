#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

#include <iostream>
#include <string>

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
  };
  std::istream& operator>>(std::istream& in, CodeNode& node);
  void swap(CodeNode& a, CodeNode& b);
  template < class Comp >
  CodeNode* merge(CodeNode* first, CodeNode* second, const Comp& comp);
  template < class Comp >
  CodeNode* mergeSort(CodeNode* list, const Comp& comp);

  template < class Comp >
  CodeNode* merge(CodeNode* first, CodeNode* second, const Comp& comp){
    if (!first){
      return second;
    }
    if (!second){
      return first;
    }
    CodeNode* firCurrent = first;
    CodeNode* secCurrent = second;
    CodeNode* result = comp(*first, *second) ? first : second;
    while (firCurrent && secCurrent){
      if (comp(*firCurrent, *secCurrent)){
        while (firCurrent->right && comp(*firCurrent->right, *secCurrent)){
          firCurrent = firCurrent->right;
        }
        CodeNode* tmp = firCurrent;
        firCurrent = firCurrent->right;
        tmp->right = secCurrent;
      }
      else{
        while (secCurrent->right && comp(*secCurrent->right, *firCurrent)){
          secCurrent = secCurrent->right;
        }
        CodeNode* tmp = secCurrent;
        secCurrent = secCurrent->right;
        tmp->right = firCurrent;
      }
    }
    return result;
  }
  template < class Comp >
  CodeNode* mergeSort(CodeNode* list, const Comp& comp){
    if (!list || !list->right){
      return list;
    }
    CodeNode* first = list;
    CodeNode* current = list;
    while (first->right){
      first = first->right;
      if (first->right){
        current = current->right;
        first = first->right;
      }
    }
    CodeNode* tmp = current;
    current = current->right;
    tmp->right = nullptr;
    CodeNode* second = current;
    first = list;
    first = mergeSort(first, comp);
    second = mergeSort(second, comp);
    list = merge(first, second, comp);
    return list;
  }
}

#endif
