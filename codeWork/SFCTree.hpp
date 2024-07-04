#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include <exception>
#include "../utils/quickSort.hpp"
#include "../utils/Node.hpp"
#include "MidNode.hpp"
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
  template < class T >
  class SFCTree
  {
    using Node = utils::Node< T >;
    public:
    //Copies the node's data
    /*
    Данные копируются. Поиск просходит по
    обходу звеньев. Не очень эффективно но
    я хз как искать по дереву чтобы было эфективно
    учитывая что оно создается на данных которые
    могут повторятся(в смысле их вероятность)
    */
    SFCTree(const CodeNode< T >* nodes, size_t size);
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
    Node* searchByKey(const T& key) const;
    void outputCodes(std::ostream& out) const;

    private:
    Node* root_;

    size_t findDivisionIndex(const CodeNode< T >* nodes, size_t size) const;
    static Node* getMin(Node* node);
    static Node* getNext(Node* node);
  };

  template < class T >
  SFCTree< T >::SFCTree(const CodeNode< T >* nodes, size_t size):
    root_(nullptr)
  {
    /*
      1. Отсортировать звенья
      2. найти место разреза
      3. разрезать
      4. 2 и 3 пока не будет по 1 звену
      5. паралельно заполнять коды
    */
    CodeNode< T >* workNodes = nullptr;
    try
    {
      workNodes = new CodeNode< T >[size]{};
      utils::copyElements(workNodes, nodes, size);
      utils::quickSort(workNodes, size, [](const CodeNode< T >& a, const CodeNode< T >& b)
        {
          return a.frequency > b.frequency;
        });
      Node* list = utils::makeIntoList(workNodes, size);
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
  template < class T >
  SFCTree< T >::~SFCTree()
  {
    Node* current = getMin(root_);
    while (current)
    {
      delete current;
      current = getNext(current);
    }
  }
  template < class T >
  typename SFCTree< T >::Node* SFCTree< T >::searchByKey(const T& key) const
  {
    Node* current = getMin(root_);
    while (current)
    {
      if (current->key == key)
      {
        return current;
      }
      current = getNext(current);
    }
    return nullptr;
  }
  template < class T >
  void SFCTree< T >::outputCodes(std::ostream& out) const
  {
    Node* current = getMin(root_);
    while (current)
    {
      out << *current;
      current = getNext(current);
    }
  }

  //Finds index AFTER which division is made
  template < class T >
  size_t SFCTree< T >::findDivisionIndex(const CodeNode< T >* nodes, size_t size) const
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
  template < class T >
  typename SFCTree< T >::Node* SFCTree< T >::getMin(Node* node)
  {
    Node* current = nullptr;
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
  template < class T >
  typename SFCTree< T >::Node* SFCTree< T >::getNext(Node* node)
  {
    if (node->right)
    {
      return getMin(node->right);
    }
    Node* current = node;
    Node* curParent = node->parent;
    while (curParent && (current == curParent->right))
    {
      current = curParent;
      curParent = curParent->parent;
    }
    return curParent;
  }
}
#endif
