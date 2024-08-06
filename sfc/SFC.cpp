#include "SFC.hpp"

namespace sfc{
  void useSfcAlgo(CodeNode* list){
    if (!list->right){
      return;
    }
    CodeNode* current = divideAndZeros(list);
    CodeNode* tmp = current;
    while (tmp){
      tmp->code += '1';
      tmp = tmp->right;
    }
    CodeNode* newList = new CodeNode;
    newList->parent = list->parent;
    codeWork::swap(*newList, *list);
    list->left = newList;
    list->right = current;
    newList->parent = list;
    current->parent = list;
    useSfcAlgo(newList);
    useSfcAlgo(current);
  }
  CodeNode* divideAndZeros(CodeNode* list){
    double barrierCount = calcGlobCount(list) * 0.5;
    CodeNode* previous = list;
    size_t sum = list->quantity;
    size_t prevSum = sum;
    do{
      list->code += '0';
      previous = list;
      list = list->right;
      prevSum = sum;
      sum += list->quantity;
    } while (list && sum < barrierCount);
    if (!list){
      throw std::logic_error("<BAD QUANTITIES>");
    }
    if (sum - barrierCount <= barrierCount - prevSum){
      list->code += '0';
      previous = list;
      list = list->right;
    }
    previous->right = nullptr;
    return list;
  }
  size_t calcGlobCount(CodeNode* list){
    double globCount = 0;
    while (list){
      globCount += list->quantity;
      list = list->right;
    }
    return globCount;
  }
}
