#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include "codeNode.hpp"

namespace codeWork
{
  class CodeTree
  {
    public:
    CodeTree();
    CodeTree(const CodeTree&) = delete;
    CodeTree(CodeTree&&) noexcept;
    virtual ~CodeTree();

    CodeTree& operator=(const CodeTree&) = delete;
    CodeTree& operator=(CodeTree&&) noexcept;

    bool searchKeyIterative(const T& key) const;
    bool insertNode(const T& key);
    bool deleteNode(const T& key);
    void inorderWalkIterative() const;
    private:
    struct Node
    {
      T key_;
      Node* left_;
      Node* right_;
      Node* p_;
      Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr):
        key_(key),
        left_(left),
        right_(right),
        p_(p)
      {}
    };
    Node* root_;

    static Node* getMin(Node* const node);
    static Node* getNext(Node* const node);
  };
}

#endif
