#include "utils.hpp"

utl::Node* utl::getNode(Node*& dest, size_t& size, const std::string& src)
{
  std::string alph = "abcdefghijklmnopqrstuvwxyz0123456789 \n";
  size_t alphLen = alph.size();
  Node* preSet = new Node[alphLen]{};
  for (size_t i = 0; i < alphLen; ++i)
  {
    preSet[i].symbol = alph[i];
  }
  for (size_t i = 0; i < src.size(); ++i)
  {
    for (size_t j = 0; j < alphLen; ++j)
    {
      if (preSet[j].symbol == src[i])
      {
        ++preSet[j].quantity;
      }
    }
  }
  utl::quickSort(preSet, alphLen, [](const Node& n1, const Node& n2)
    {
      return n1.quantity <= n2.quantity;
    });
  size_t i = 0;
  for (;i < alphLen; ++i)
  {
    if (preSet[i].quantity > 0)
    {
      break;
    }
  }
  Node* set = new Node[alphLen - i];
  utl::copyElements(set, &preSet[i], alphLen - i);
  delete[] preSet;
  size = alphLen - i;
  utl::swap(dest, set);
  delete[] set;

  return dest;
}
