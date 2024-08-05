#include "SFCTree.hpp"

namespace codeWork{
  SFCTree::SFCTree(): root(nullptr){}
  SFCTree::SFCTree(std::istream& in, bool isCodeFile): root(nullptr){
    root = new CodeNode();
    isCodeFile ? readTree(in) : makeTree(in);
  }
  SFCTree::SFCTree(SFCTree&& src): root(src.root){
    if (this != &src){
      src.root = nullptr;
    }
  }
  SFCTree::~SFCTree(){
    delete root;
  }

  SFCTree& SFCTree::operator=(SFCTree&& src){
    if (this != &src){
      root = src.root;
      src.root = nullptr;
    }
    return *this;
  }

  void SFCTree::print(std::ostream& out){
    //out << size << '\n';
    CodeNode* current = getMin(root);
    while (current){
      if (current->key){
        out << current->key << '\n';
      }
      current = getNext(current);
    }
  }
  std::string SFCTree::findCode(char key){

  }
  char SFCTree::findKey(const std::string& code){

  }
  size_t SFCTree::getMaxCodeLength(){

  }
  size_t SFCTree::getMinCodeLength(){

  }

  void SFCTree::makeTree(std::istream& in){
    char tmp = 0;
    bool isFound = false;
    CodeNode* current = root;
    in >> std::noskipws;
    while (!in.eof()){
      current = root;
      isFound = false;
      in >> tmp;
      while (current->right){
        if (current->key == tmp){
          ++current->quantity;
          isFound = true;
          break;
        }
        current = current->right;
      }
      if (current->key == tmp){
        ++current->quantity;
        isFound = true;
      }
      if (!isFound){
        try{
          CodeNode* newNode = new CodeNode(tmp, 1);
          current->right = newNode;
        }
        catch (const std::bad_alloc&){
          throw std::logic_error("<COULD NOT CREATE DICTIONARY>");
        }
      }
    }
    //mergeSortList(list);
    //fillCodesMakeTree
  }
  void SFCTree::readTree(std::istream& in){

  }

  CodeNode* SFCTree::getMin(CodeNode* node){
    CodeNode* current = nullptr;
    if (node){
      current = node;
      while (current->left){
        current = current->left;
      }
    }
    return current;
  }
  CodeNode* SFCTree::getNext(CodeNode* node){
    if (node->right){
      return getMin(node->right);
    }
    CodeNode* current = node;
    CodeNode* curParent = node->parent;
    while (curParent && (current == curParent->right)){
      current = curParent;
      curParent = curParent->parent;
    }
    return curParent;

  }
}
