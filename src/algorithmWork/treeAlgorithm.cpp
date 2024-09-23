#include "treeAlgorithm.hpp"

namespace algorithmWork{
  void listToTree(codeWork::CodeNode* list){
    if (!list->right){
      return;
    }
    codeWork::CodeNode* current = divideAndZeros(list);
    codeWork::CodeNode* tmp = current;
    while (tmp){
      tmp->code += '1';
      tmp = tmp->right;
    }
    codeWork::CodeNode* newList = new codeWork::CodeNode;
    newList->parent = list->parent;
    codeWork::swap(*newList, *list);
    list->left = newList;
    list->right = current;
    newList->parent = list;
    current->parent = list;
    listToTree(newList);
    listToTree(current);
  }
  codeWork::CodeNode* divideAndZeros(codeWork::CodeNode* list){
    double barrierCount = calcGlobCount(list) * 0.5;
    codeWork::CodeNode* previous = list;
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
  size_t calcGlobCount(codeWork::CodeNode* list){
    double globCount = 0;
    while (list){
      globCount += list->quantity;
      list = list->right;
    }
    return globCount;
  }
}
