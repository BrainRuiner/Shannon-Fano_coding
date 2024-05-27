#include "utils.hpp"

bool utl::isLessQuantity(const Node& n1, const Node& n2)
{
  return n1.quantity < n2.quantity;
}

utl::Node* utl::sortByQuantity(Node* nodes, size_t size)
{
  return quickSort(nodes, size, isLessQuantity);
}
