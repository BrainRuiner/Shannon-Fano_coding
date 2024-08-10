#ifndef CODE_TREE_HPP
#define CODE_TREE_HPP

#include <iostream>
#include "CodeNode.hpp"

#define FROM_CODE_FILE true

namespace codeWork{
  class CodeTree{
    public:
    CodeTree();
    CodeTree(std::istream& in, bool isCodeFile = false);
    CodeTree(const CodeTree& src) = delete;
    CodeTree(CodeTree&& src);
    ~CodeTree();

    CodeTree& operator=(const CodeTree& src) = delete;
    CodeTree& operator=(CodeTree&& src);

    void print(std::ostream& out);
    std::string findCode(char key);
    char findKey(const std::string& code);
    size_t getMaxCodeLength();
    size_t getMinCodeLength();

    private:
    CodeNode* root;

    void makeTree(std::istream& in);
    void readTree(std::istream& in);

    CodeNode* getMin(CodeNode* node);
    CodeNode* getNext(CodeNode* node);
  };
}

#endif
