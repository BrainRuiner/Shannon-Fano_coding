#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include <exception>
#include "CodeNode.hpp"
#include "../utils/quickSort.hpp"

namespace codeWork
{
  //Should rename to SFCTree probably
  template <class T>
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
    SFCTree(const CodeNode<T>* nodes, size_t size);
    SFCTree(const SFCTree&) = delete;
    SFCTree(SFCTree&&) = delete;
    //сделать обход и удалять элеметны общей 
    //функцией с поиском и выводом
    virtual ~SFCTree();

    SFCTree& operator=(const SFCTree&) = delete;
    SFCTree& operator=(SFCTree&&) = delete;

    //Shit. Needs rewriting
    //Можно удалить а в деструктор вставить то что
    //я написал выше
    bool deleteNode(const T& key);
    /*
    Both those funcs are kinda similiar.
    Should make common func wich goes through
    nodes and use functor on it
    */
    CodeNode<T>* searchKey(const T& key) const;
    void outputCodes(std::ostream& out) const;

    private:
    CodeNode<T>* root_;

    size_t findDivisionIndex(const CodeNode<T>* nodes, size_t size) const;
    static CodeNode<T>* getMin(CodeNode<T>* node);
    static CodeNode<T>* getNext(CodeNode<T>* node);
  };

  template <class T>
  SFCTree<T>::SFCTree(const CodeNode<T>* nodes, size_t size):
    root_(nullptr)
  {
    /*
      1. Отсортировать звенья
      2. найти место разреза
      3. разрезать
      4. 2 и 3 пока не будет по 1 звену
      5. паралельно заполнять коды
    */
    CodeNode<T>* workNodes = nullptr;
    try
    {
      workNodes = new CodeNode<T>[size]{};
      utils::copyElements(workNodes, nodes, size);
      utils::quickSort(workNodes, size, [](const CodeNode<T>& a, const CodeNode<T>& b)
        {
          return a.frequency > b.frequency;
        });
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
  template <class T>
  SFCTree<T>::~SFCTree()
  {
    while (root_)
    {
      deleteNode(root_->key);
    }
  }
  template <class T>
  bool SFCTree<T>::deleteNode(const T& key)
  {
    CodeNode<T>* toTermination = searchKey(key);
    if (!toTermination)
    {
      return false;
    }

    CodeNode<T>* parent = toTermination->parent;
    if (!parent && (!toTermination->left && !toTermination->right))
    {
      root_ = nullptr;
    }
    else if (!toTermination->left && !toTermination->right)
    {
      if (parent->left == toTermination)
      {
        parent->left = nullptr;
      }
      if (parent->right == toTermination)
      {
        parent->right = nullptr;
      }
    }
    else if (!parent && (!toTermination->left || !toTermination->right))
    {
      if (toTermination->left)
      {
        root_ = toTermination->left;
        toTermination->left->parent = nullptr;
      }
      else
      {
        root_ = toTermination->right;
        toTermination->right->parent = nullptr;
      }
    }
    else if (!toTermination->left || !toTermination->right)
    {
      if (toTermination->left)
      {
        if (parent->left == toTermination)
        {
          parent->left = toTermination->left;
        }
        else
        {
          parent->right = toTermination->left;
        }
        toTermination->left->parent = parent;
      }
      else
      {
        if (parent->left == toTermination)
        {
          parent->left = toTermination->right;
        }
        else
        {
          parent->right = toTermination->right;
        }
        toTermination->right->parent = parent;
      }
    }
    else
    {
      CodeNode<T>* successor = getNext(toTermination);
      toTermination->key = successor->key;
      if (successor->parent->left == successor)
      {
        successor->parent->left = successor->right;
        if (successor->right)
        {
          successor->right->parent = successor->parent;
        }
      }
      else
      {
        successor->parent->right = successor->right;
        if (successor->right)
        {
          successor->right->parent = successor->parent;
        }
      }
      toTermination = successor;
    }
    delete toTermination;
    return true;
  }
  template <class T>
  CodeNode<T>* SFCTree<T>::searchKey(const T& key) const
  {
    CodeNode<T>* current = getMin(root_);
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
  template <class T>
  void SFCTree<T>::outputCodes(std::ostream& out) const
  {
    CodeNode<T>* current = getMin(root_);
    while (current)
    {
      out << *current;
      current = getNext(current);
    }
  }

  //Finds index AFTER which division is made
  template <class T>
  size_t SFCTree<T>::findDivisionIndex(const CodeNode<T>* nodes, size_t size) const
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
  template <class T>
  CodeNode<T>* SFCTree<T>::getMin(CodeNode<T>* node)
  {
    CodeNode<T>* current = nullptr;
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
  template <class T>
  CodeNode<T>* SFCTree<T>::getNext(CodeNode<T>* node)
  {
    if (node->right)
    {
      return getMin(node->right);
    }
    CodeNode<T>* current = node;
    CodeNode<T>* curParent = node->parent;
    while (curParent && (current == curParent->right))
    {
      current = curParent;
      curParent = curParent->parent;
    }
    return curParent;
  }
}
#endif
