#include "SFCTree.hpp"
#include "../sfc/SFC.hpp"

namespace codeWork{
  SFCTree::SFCTree(): root(nullptr){}
  SFCTree::SFCTree(std::istream& in, bool isCodeFile): root(nullptr){
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
    CodeNode* current = getMin(root);
    while (current){
      if (current->key){
        out << current->key << ':' << current->code << '\n';
      }
      current = getNext(current);
    }
  }
  std::string SFCTree::findCode(char key){
    CodeNode* current = getMin(root);
    while (current){
      if (current->key == key){
        return current->code;
      }
      current = getNext(current);
    }
    throw std::logic_error("KEY NOT FOUND");
  }
  char SFCTree::findKey(const std::string& code){
    CodeNode* current = root;
    for (size_t i = 0; i < code.length(); ++i){
      if (code[i] == '0'){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }
    if (!current->key){
      throw std::logic_error("CODE NOT FOUND");
    }
    return current->key;
  }
  size_t SFCTree::getMaxCodeLength(){
    if (root){
      CodeNode* current = root;
      while (current->right){
        current = current->right;
      }
      return current->code.length();
    }
    return 0;
  }
  size_t SFCTree::getMinCodeLength(){
    if (root){
      CodeNode* current = root;
      while (current->left){
        current = current->right;
      }
      return current->code.length();
    }
    return 0;
  }

  void SFCTree::makeTree(std::istream& in){
    char tmp = 0;
    bool isFound = false;
    CodeNode* current = nullptr;
    in >> std::noskipws;
    while (!in.eof()){
      current = root;
      isFound = false;
      in >> tmp;
      while (current && current->right){
        if (current->key == tmp){
          ++current->quantity;
          isFound = true;
          break;
        }
        current = current->right;
      }
      if (current && current->key == tmp){
        ++current->quantity;
        isFound = true;
      }
      if (!isFound){
        try{
          CodeNode* newNode = new CodeNode(tmp, 1);
          if (!current){
            root = newNode;
          }
          else{
            current->right = newNode;
          }
        }
        catch (const std::bad_alloc&){
          throw std::logic_error("<COULD NOT CREATE DICTIONARY>");
        }
      }
    }
    root = mergeSort(root,
      [](const CodeNode& a, const CodeNode& b){
        return a.quantity >= b.quantity;
      });
    sfc::useSfcAlgo(root);
  }
  void SFCTree::readTree(std::istream& in){
    try{
      if (!root){
        root = new CodeNode;
      }
      in >> std::noskipws;
      while (!in.eof()){
        CodeNode* newNode = new CodeNode;
        in >> *newNode;
        CodeNode* current = root;
        for (size_t i = 0; i < newNode->code.length() - 1; ++i){
          if (newNode->code[i] == '0'){
            if (!current->left){
              CodeNode* newLeft = new CodeNode;
              current->left = newLeft;
              newLeft->parent = current;
            }
            current = current->left;
          }
          else{
            if (!current->right){
              CodeNode* newRight = new CodeNode;
              current->right = newRight;
              newRight->parent = current;
            }
            current = current->right;
          }
        }
        if (newNode->code[newNode->code.length() - 1] == '0'){
          current->left = newNode;
        }
        else{
          current->right = newNode;
        }
        newNode->parent = current;
      }
    }
    catch (...){
      throw std::logic_error("COULD NOT READ CODES");
    }
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
