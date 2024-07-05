#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include <exception>
#include "../utils/quickSort.hpp"
#include "CodeNode.hpp"

/*
  Возможно хорошей идеей будет использовать
список вместо массивов. Особенно учитывая
как часто мне нужно делить данные на группы.
  Для массивов это будет сложной фигней с пере-
распределением памяти, а для списков - нет.
*/

namespace codeWork
{
  class SFCTree
  {
    public:
    //Copies the node's data
    /*
    Данные копируются. Поиск просходит по
    обходу звеньев. Не очень эффективно но
    я хз как искать по дереву чтобы было эфективно
    учитывая что оно создается на данных которые
    могут повторятся(в смысле их вероятность)
    */
    SFCTree(const CodeNode* nodes, size_t size);
    SFCTree(const SFCTree&) = delete;
    SFCTree(SFCTree&&) = delete;
    //сделать обход и удалять элеметны общей 
    //функцией с поиском и выводом
    virtual ~SFCTree();

    SFCTree& operator=(const SFCTree&) = delete;
    SFCTree& operator=(SFCTree&&) = delete;
    /*
    Both those funcs are kinda similiar.
    Should make common func wich goes through
    nodes and use functor on it
    */
    std::string searchCodeByKey(char key) const;
    void outputCodes(std::ostream& out) const;

    private:
    CodeNode* root_;

    size_t findDivisionIndex(const CodeNode* nodes, size_t size) const;
    void makeTree(CodeNode* node);
    static CodeNode* getMin(CodeNode* node);
    static CodeNode* getNext(CodeNode* node);
  };

  SFCTree::SFCTree(const CodeNode* nodes, size_t size):
    root_(nullptr)
  {
    /*
      1. Отсортировать звенья
      2. найти место разреза
      3. разрезать
      4. 2 и 3 пока не будет по 1 звену
      5. паралельно заполнять коды
    */
    CodeNode* workNodes = nullptr;
    try
    {
      workNodes = new CodeNode[size]{};
      utils::copyElements(workNodes, nodes, size);
      utils::quickSort(workNodes, size, [](const CodeNode& a, const CodeNode& b)
        {
          return a.frequency > b.frequency;
        });
      // Node* list = utils::makeIntoList(workNodes, size);
      size_t divisionIndex = findDivisionIndex(workNodes, size);


    }
    catch (const std::bad_alloc&)
    {
      throw std::logic_error("<BAD SIZE>");
    }
    catch (...)
    {
      throw;
    }
  }
  SFCTree::~SFCTree()
  {
    CodeNode* current = getMin(root_);
    while (current)
    {
      delete current;
      current = getNext(current);
    }
  }
  std::string SFCTree::searchCodeByKey(char key) const
  {
    CodeNode* current = getMin(root_);
    while (current)
    {
      if (current->getKey() == key)
      {
        return current->code;
      }
      current = getNext(current);
    }
    return nullptr;
  }
  void SFCTree::outputCodes(std::ostream& out) const
  {
    CodeNode* current = getMin(root_);
    while (current)
    {
      if (current->getKey() != '\0')
      {
        out << *current << '\n';
      }
      current = getNext(current);
    }
  }

  //Finds index AFTER which division is made
  size_t SFCTree::findDivisionIndex(const CodeNode* nodes, size_t size) const
  {
    double freqSum = 0.0;
    double lastFreqSum = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
      freqSum += nodes[i].frequency;
      if (freqSum >= 0.5)
      {
        return i - (0.5 - lastFreqSum < freqSum - 0.5);
      }
      lastFreqSum = freqSum;
    }
    throw std::logic_error("<FREQUENCYS ERROR>");
  }
  // void SFCTree::makeTree(CodeNode* node)
  // {
  //   if (!node)
  //   {
  //     return;
  //   }

  //   size_t divIndex = findDivisionIndex(node)
  // }
  CodeNode* SFCTree::getMin(CodeNode* node)
  {
    CodeNode* current = nullptr;
    if (node)
    {
      current = node;
      while (current->left)
      {
        current = current->left;
      }
    }
    return current;
  }
  CodeNode* SFCTree::getNext(CodeNode* node)
  {
    if (node->right)
    {
      return getMin(node->right);
    }
    CodeNode* current = node;
    CodeNode* curParent = node->parent;
    while (curParent && (current == curParent->right))
    {
      current = curParent;
      curParent = curParent->parent;
    }
    return curParent;
  }
}
#endif
