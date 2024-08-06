#ifndef SFC_TREE_HPP
#define SFC_TREE_HPP

#include "CodeNode.hpp"

#define FROM_CODE_FILE true

namespace codeWork{
  class SFCTree{
    public:
    SFCTree();
    SFCTree(std::istream& in, bool isCodeFile = false);
    SFCTree(const SFCTree& src) = delete;
    SFCTree(SFCTree&& src);
    ~SFCTree();

    SFCTree& operator=(const SFCTree& src) = delete;
    SFCTree& operator=(SFCTree&& src);

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
