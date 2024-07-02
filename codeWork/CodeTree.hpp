#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <ostream>
#include "codeNode.hpp"

namespace codeWork
{
  //Should rename to SFCTree probably
  template <class T>
  class CodeTree
  {
    public:
    //Copies the node's data
    CodeTree(const CodeNode* nodes, size_t size);
    CodeTree(const CodeTree&) = delete;
    CodeTree(CodeTree&&) = delete;
    virtual ~CodeTree();

    CodeTree& operator=(const CodeTree&) = delete;
    CodeTree& operator=(CodeTree&&) = delete;

    //depend on searchKey so does not work too
    //(Anyway it it is shit so needs refactoring)
    //I use it only for destructor so maybe 
    //I should delete it and write all in 
    //destructor
    bool deleteNode(const T& key);
    //It is search for binary tree, not SFC tree. 
    //So it does not work.
    CodeNode* searchKey(const T& key) const;
    void outputCodes(std::ostream& out) const;

    private:
    CodeNode* root_;

    //To my surprise they are not affected by
    //searchkey issue, because they use pointers
    //and don't compare elements
    static CodeNode* getMin(CodeNode* const node);
    static CodeNode* getNext(CodeNode* const node);
  };

  template <class T>
  CodeTree<T>::CodeTree(const CodeNode* nodes, size_t size)
  {
    //insert Shannon-Fano algorithm
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
  CodeNode* CodeTree<T>::searchKey(const T& key) const
  {
    CodeNode* current = root_;
    while (current && (current->key_ != key))
    {
      if (current->key_ < key)
      {
        current = current->right_;
      }
      else
      {
        current = current->left_;
      }
    }
    return current;
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
  CodeNode* CodeTree<T>::getMin(CodeNode* const node)
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
  CodeNode* CodeTree<T>::getNext(CodeNode* const node)
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
