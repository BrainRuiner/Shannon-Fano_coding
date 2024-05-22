#include <iostream>
#include "BinarySearchTree.hpp"

int main()
{
  bst::BinarySearchTree< char > tree;
  tree.insertNode('c');
  tree.insertNode('b');
  tree.insertNode('z');
  tree.insertNode('d');
  tree.insertNode('a');

  tree.output(std::cout);
  std::cout << tree.getPath('a') << ' ' << tree.getPath('z') << '\n';
  return 0;
}
