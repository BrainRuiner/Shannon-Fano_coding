#include "treeAlgorithm.hpp"

namespace awk{
  void listToTree(cwk::CodeNode* list){
    if (!list->right){
      return;
    }
    cwk::CodeNode* current = divideAndZeros(list);
    cwk::CodeNode* tmp = current;
    while (tmp){
      tmp->code += '1';
      tmp = tmp->right;
    }
    cwk::CodeNode* newList = new cwk::CodeNode;
    newList->parent = list->parent;
    cwk::swap(*newList, *list);
    list->left = newList;
    list->right = current;
    newList->parent = list;
    current->parent = list;
    listToTree(newList);
    listToTree(current);
  }
  cwk::CodeNode* divideAndZeros(cwk::CodeNode* list){
    double barrierCount = calcGlobCount(list) * 0.5;
    cwk::CodeNode* previous = list;
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
  size_t calcGlobCount(cwk::CodeNode* list){
    double globCount = 0;
    while (list){
      globCount += list->quantity;
      list = list->right;
    }
    return globCount;
  }
}
