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
  void swap(CodeNode& a, CodeNode& b);
  CodeNode* pushCodeArr(CodeNode* nodes, size_t size);
  CodeNode* pullArr(CodeNode* dest, DictionaryNode* origin, size_t size);
  //Connects nodes like they are list
  //DOES NOT COPY
  CodeNode* makeIntoList(CodeNode* nodes, size_t size);
  template < class Comp >
  CodeNode* merge(CodeNode* first, CodeNode* second, const Comp& comp);
  template < class Comp >
  CodeNode* mergeSort(CodeNode* list, const Comp& comp);
  void print(CodeNode* list);

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
    std::cout << "first: ";
    print(first);
    std::cout << "sceond: ";
    print(second);
    list = merge(first, second, comp);
    std::cout << "list: ";
    print(list);
    return list;
  }
}

#endif
