#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include <exception>
#include "CodeNode.hpp"
#include "../utils/utils.hpp"

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
    virtual ~SFCTree();

    SFCTree& operator=(const SFCTree&) = delete;
    SFCTree& operator=(SFCTree&&) = delete;

    //Shit. Needs rewriting
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
    static CodeNode<T>* getMin(const CodeNode<T>* node);
    static CodeNode<T>* getNext(const CodeNode<T>* node);
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

    }
    catch (const std::bad_alloc&)
    {
      throw std::logic_error("<BAD_MEMORY>");
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
      deleteNode(root_->key_);
    }
  }
  template <class T>
  bool SFCTree<T>::deleteNode(const T& key)
  {
    CodeNode* toTermination = searchNodeIterative(key);
    if (!toTermination)
    {
      return false;
    }

    CodeNode* parent = toTermination->p_;
    if (!parent && (!toTermination->left_ && !toTermination->right_))
    {
      root_ = nullptr;
    }
    else if (!toTermination->left_ && !toTermination->right_)
    {
      if (parent->left_ == toTermination)
      {
        parent->left_ = nullptr;
      }
      if (parent->right_ == toTermination)
      {
        parent->right_ = nullptr;
      }
    }
    else if (!parent && (!toTermination->left_ || !toTermination->right_))
    {
      if (toTermination->left_)
      {
        root_ = toTermination->left_;
        toTermination->left_->p_ = nullptr;
      }
      else
      {
        root_ = toTermination->right_;
        toTermination->right_->p_ = nullptr;
      }
    }
    else if (!toTermination->left_ || !toTermination->right_)
    {
      if (toTermination->left_)
      {
        if (parent->left_ == toTermination)
        {
          parent->left_ = toTermination->left_;
        }
        else
        {
          parent->right_ = toTermination->left_;
        }
        toTermination->left_->p_ = parent;
      }
      else
      {
        if (parent->left_ == toTermination)
        {
          parent->left_ = toTermination->right_;
        }
        else
        {
          parent->right_ = toTermination->right_;
        }
        toTermination->right_->p_ = parent;
      }
    }
    else
    {
      CodeNode* successor = getNext(toTermination);
      toTermination->key_ = successor->key_;
      if (successor->p_->left_ == successor)
      {
        successor->p_->left_ = successor->right_;
        if (successor->right_)
        {
          successor->right_->p_ = successor->p_;
        }
      }
      else
      {
        successor->p_->right_ = successor->right_;
        if (successor->right_)
        {
          successor->right_->p_ = successor->p_;
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
    CodeNode* current = getMin(root_);
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
    CodeNode* current = getMin(root_);
    while (current)
    {
      out << *current;
      current = getNext(current);
    }
  }

  template <class T>
  size_t SFCTree<T>::findDivisionIndex(const CodeNode<T>* nodes, size_t size) const
  {
    double freqSum = 0.0;
    double lastFreqSum = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
      freqSum += nodes[i]->frequency;
      if (freqSum >= 0.5)
      {
        return i - (0.5 - lastFreqSum < freqSum - 0.5);
      }
      lastFreqSum = freqSum;
    }
    throw std::logic_error("<FREQUENCYS ERROR>");
  }
  template <class T>
  CodeNode<T>* SFCTree<T>::getMin(const CodeNode<T>* node)
  {
    CodeNode* current = nullptr;
    if (node)
    {
      current = node;
      while (current->left_)
      {
        current = current->left_;
      }
    }
    return current;
  }
  template <class T>
  CodeNode<T>* SFCTree<T>::getNext(const CodeNode<T>* node)
  {
    if (node->right_)
    {
      return getMin(node->right_);
    }
    CodeNode* current = node;
    CodeNode* curParent = node->p_;
    while (curParent && (current == curParent->right_))
    {
      current = curParent;
      curParent = curParent->p_;
    }
    return curParent;
  }
}
#endif
