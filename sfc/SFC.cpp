// #include "SFC.hpp"
// #include <iostream>
// #include "../utils/quickSort.hpp"
// #include "../utils/utils.hpp"

// namespace sfc{
//   void print(CodeNode* list){
//     while (list){
//       std::cout << list->key << ' ' << list->code << '\n';
//       list = list->next;
//     }
//   }

//   DictNode* fillCodes(DictNode* nodes, size_t size){
//     CodeNode* workNodes = nullptr;
//     try{
//       workNodes = new CodeNode[size];
//       codeWork::pullArr(workNodes, nodes, size);
//       checkAndSort(workNodes, size);
//       CodeNode* list = codeWork::makeIntoList(workNodes, size);
//       useSfcAlgo(list);
//       codeWork::pushCodeArr(workNodes, size);
//       delete[] workNodes;
//     }
//     catch (const std::bad_alloc& e){
//       throw std::logic_error("<WRONG SIZE>");
//     }
//     catch (...){
//       delete[] workNodes;
//       throw;
//     }
//     return nodes;
//   }
//   void useSfcAlgo(CodeNode* list){
//     if (!list->next){
//       return;
//     }
//     CodeNode* current = divideAndZeros(list);
//     CodeNode* tmp = current;
//     while (tmp){
//       tmp->code += '1';
//       tmp = tmp->next;
//     }
//     useSfcAlgo(list);
//     useSfcAlgo(current);
//   }
//   CodeNode* divideAndZeros(CodeNode* list){
//     double barrierCount = calcGlobCount(list) * 0.5;
//     CodeNode* previous = list;
//     size_t sum = list->quantity;
//     size_t prevSum = sum;
//     do{
//       list->code += '0';
//       previous = list;
//       list = list->next;
//       prevSum = sum;
//       sum += list->quantity;
//     } while (list && sum < barrierCount);
//     if (!list){
//       throw std::logic_error("<BAD QUANTITIES>");
//     }
//     if (sum - barrierCount <= barrierCount - prevSum){
//       list->code += '0';
//       previous = list;
//       list = list->next;
//     }
//     previous->next = nullptr;
//     return list;
//   }
//   size_t calcGlobCount(CodeNode* list){
//     double globCount = 0;
//     while (list){
//       globCount += list->quantity;
//       list = list->next;
//     }
//     return globCount;
//   }
//   CodeNode* checkAndSort(CodeNode* nodes, size_t size){
//     for (size_t i = 0; i < size; ++i){
//       if (nodes[i].quantity < nodes[i + 1].quantity){
//         utils::quickSort(nodes, size,
//           [](const CodeNode& a, const CodeNode& b){
//             return a.quantity > b.quantity;
//           });
//         return nodes;
//       }
//     }
//     return nodes;
//   }
// }
