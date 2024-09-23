#include "CodeTree.hpp"
#include "../algorithmWork/treeAlgorithm.hpp"

namespace codeWork{
  CodeTree::CodeTree(): root(nullptr){}
  CodeTree::CodeTree(std::istream& in, bool isCodeFile): root(nullptr){
    isCodeFile ? readTree(in) : makeTree(in);
  }
  CodeTree::CodeTree(CodeTree&& src): root(src.root){
    if (this != &src){
      src.root = nullptr;
    }
  }
  CodeTree::~CodeTree(){
    delete root;
  }

  CodeTree& CodeTree::operator=(CodeTree&& src){
    if (this != &src){
      root = src.root;
      src.root = nullptr;
    }
    return *this;
  }

  void CodeTree::print(std::ostream& out){
    CodeNode* current = getMin(root);
    while (current){
      if (current->key){
        out << current->key << ':' << current->code << '\n';
      }
      current = getNext(current);
    }
  }
  std::string CodeTree::findCode(char key){
    CodeNode* current = getMin(root);
    while (current){
      if (current->key == key){
        return current->code;
      }
      current = getNext(current);
    }
    throw std::logic_error("KEY NOT FOUND");
  }
  char CodeTree::findKey(const std::string& code){
    CodeNode* current = root;
    for (size_t i = 0; current && i < code.length(); ++i){
      if (code[i] == '0'){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }
    if (!current || !current->key){
      throw std::logic_error("CODE NOT FOUND");
    }
    return current->key;
  }
  size_t CodeTree::getMaxCodeLength(){
    if (root){
      CodeNode* current = root;
      while (current->right){
        current = current->right;
      }
      return current->code.length();
    }
    return 0;
  }
  size_t CodeTree::getMinCodeLength(){
    if (root){
      CodeNode* current = root;
      while (current->left){
        current = current->left;
      }
      return current->code.length();
    }
    return 0;
  }

  void CodeTree::makeTree(std::istream& in){
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
          throw std::logic_error("<COULD NOT CREATE TREE>");
        }
      }
    }
    root = mergeSort(root,
      [](const CodeNode& a, const CodeNode& b){
        return a.quantity >= b.quantity;
      });
    algorithmWork::listToTree(root);
  }
  void CodeTree::readTree(std::istream& in){
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

  CodeNode* CodeTree::getMin(CodeNode* node){
    CodeNode* current = nullptr;
    if (node){
      current = node;
      while (current->left){
        current = current->left;
      }
    }
    return current;
  }
  CodeNode* CodeTree::getNext(CodeNode* node){
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
