#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include "CodeNode.hpp"

namespace codeWork
{
  //Should rename to SFCTree probably
  template <class T>
  class CodeTree
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
    CodeTree(const CodeNode<T>* nodes, size_t size);
    CodeTree(const CodeTree&) = delete;
    CodeTree(CodeTree&&) = delete;
    virtual ~CodeTree();

    CodeTree& operator=(const CodeTree&) = delete;
    CodeTree& operator=(CodeTree&&) = delete;

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

    static CodeNode<T>* getMin(CodeNode<T>* const node);
    static CodeNode<T>* getNext(CodeNode<T>* const node);
  };

  template <class T>
  CodeTree<T>::CodeTree(const CodeNode<T>* nodes, size_t size):
    root_(nullptr)
  {

  }
  template <class T>
  CodeTree<T>::~CodeTree()
  {
    while (root_)
    {
      deleteNode(root_->key_);
    }
  }
  template <class T>
  bool CodeTree<T>::deleteNode(const T& key)
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
  CodeNode<T>* CodeTree<T>::searchKey(const T& key) const
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
  void CodeTree<T>::outputCodes(std::ostream& out) const
  {
    CodeNode* current = getMin(root_);
    while (current)
    {
      out << *current;
      current = getNext(current);
    }
  }
  template <class T>
  CodeNode<T>* CodeTree<T>::getMin(CodeNode<T>* const node)
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
  CodeNode<T>* CodeTree<T>::getNext(CodeNode<T>* const node)
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
