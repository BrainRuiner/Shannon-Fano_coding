#include "CodeNode.hpp"
#include "../utils/Delimiter.hpp"

namespace codeWork{
  CodeNode::CodeNode(char k, size_t q, const std::string& c,
    CodeNode* r, CodeNode* l, CodeNode* p)
    : key(k), quantity(q), code(c), right(r), left(l), parent(p){}
  CodeNode::~CodeNode(){
    delete left;
    delete right;
  }
  std::istream& operator>>(std::istream& in, CodeNode& node){
    std::istream::sentry guard(in);
    if (!guard){
      return in;
    }
    in >> std::noskipws;
    CodeNode input;
    using del = utils::DelimiterI;
    in >> input.key >> del{ ':' } >> input.code >> del{ '\n' };
    in.peek();
    if (in){
      node = input;
    }
    return in;
  }
  void swap(CodeNode& a, CodeNode& b){
    CodeNode tmp(a);
    a = b;
    b = tmp;
  }
  void print(CodeNode* list){
    while (list){
      std::cout << list->key;
      list = list->right;
    }
    std::cout << '\n';
  }
}
