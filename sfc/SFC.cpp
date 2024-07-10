#include "SFC.hpp"
#include <iostream>

namespace sfc
{
  void print(CodeNode* list)
  {
    while (list)
    {
      std::cout << list->key << ' ' << list->code << '\n';
      list = list->next;
    }
  }

  DictNode* fillCodes(DictNode* nodes, size_t size)
  {

  }
  void useSfcAlgo(CodeNode* list)
  {
    if (!list->next)
    {
      return;
    }
    CodeNode* current = divideAndZeros(list);
    CodeNode* tmp = current;
    while (tmp)
    {
      tmp->code += '1';
      tmp = tmp->next;
    }
    useSfcAlgo(list);
    useSfcAlgo(current);
  }
  CodeNode* divideAndZeros(CodeNode* list)
  {
    double barrierCount = calcGlobCount(list) * 0.5;
    CodeNode* previous = list;
    size_t sum = list->quantity;
    size_t prevSum = sum;
    do
    {
      list->code += '0';
      previous = list;
      list = list->next;
      prevSum = sum;
      sum += list->quantity;
    } while (list && sum < barrierCount);
    if (!list)
    {
      throw std::logic_error("<BAD QUANTITIES>");
    }
    if (sum - barrierCount <= barrierCount - prevSum)
    {
      list->code += '0';
      previous = list;
      list = list->next;
    }
    previous->next = nullptr;
    return list;
  }
  size_t calcGlobCount(CodeNode* list)
  {
    double globCount = 0;
    while (list)
    {
      globCount += list->quantity;
      list = list->next;
    }
    return globCount;
  }
}
