#include "CodeNode.hpp"

namespace codeWork{
  CodeNode::CodeNode(char k, size_t q, const std::string& c,
    CodeNode* r, CodeNode* l, CodeNode* p)
    : key(k), quantity(q), code(c), right(r), left(l), parent(p){}
  CodeNode::~CodeNode(){
    delete left;
    delete right;
  }
  void swap(CodeNode& a, CodeNode& b){
    CodeNode tmp(a);
    a = b;
    b = tmp;
  }
  CodeNode* makeIntoList(CodeNode* nodes, size_t size){
    for (size_t i = 0; i < size - 1; ++i){
      nodes[i].right = &nodes[i + 1];
    }
    return nodes;
  }
  void print(std::ostream& out, const CodeNode* nodes, size_t size){
    for (size_t i = 0; i < size; ++i){
      out << nodes[i].key << ' ' << nodes[i].code << '\n';
    }
  }
  void print(CodeNode* list){
    while (list){
      std::cout << list->key;
      list = list->right;
    }
    std::cout << '\n';
  }
}
