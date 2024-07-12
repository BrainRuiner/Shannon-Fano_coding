#include "DictionaryNode.hpp"
#include "../utils/utils.hpp"
#include "../utils/Delimiter.hpp"
#include "../sfc/SFC.hpp"

namespace codeWork
{
  DictionaryNode::DictionaryNode(char k,
    size_t q,
    const std::string& c):
    key(k),
    quantity(q),
    code(c)
  {}

  std::ostream& operator<<(std::ostream& out,
    const DictionaryNode& node)
  {
    return out << node.key << ':' << node.code;
  }
  std::istream& operator>>(std::istream& in, DictionaryNode& node)
  {
    std::istream::sentry guard(in);
    if (!guard)
    {
      return in;
    }
    using del = utils::DelimiterI;
    in >> node.key >> del{ ':' } >> node.code >> del{ '\n' };
  }
  DictionaryNode* makeDictionary(std::istream& in,
    size_t& size,
    DictionaryNode* nodes)
  {
    if (!nodes)
    {
      size = 0;
    }
    char tmp = 0;
    in >> std::noskipws;
    DictionaryNode* newNodes = nullptr;
    bool isFound = false;
    while (!in.eof())
    {
      isFound = false;
      in >> tmp;
      for (size_t i = 0; i < size; ++i)
      {
        if (nodes[i].key == tmp)
        {
          ++nodes[i].quantity;
          isFound = true;
        }
      }
      if (!isFound)
      {
        try
        {
          newNodes = new DictionaryNode[++size];
          utils::copyElements(newNodes, nodes, size - 1);
          newNodes[size - 1].key = tmp;
          newNodes[size - 1].quantity = 1;
          delete[] nodes;
          nodes = newNodes;
        }
        catch (const std::bad_alloc&)
        {
          throw std::logic_error("<COULD NOT CREATE DICTIONARY>");
        }
      }
    }
    sfc::fillCodes(nodes, size);
    return nodes;
  }
  DictionaryNode* readDictionary(std::istream& in,
    size_t& size,
    DictionaryNode* nodes)
  {
    try
    {
      in >> std::noskipws;
      using del = utils::DelimiterI;
      in >> size >> del{ '\n' };
      nodes = new DictionaryNode[size];
      for (size_t i = 0; i < size; ++i)
      {
        in >> nodes[i];
      }
      return nodes;
    }
    catch (...)
    {
      throw std::logic_error("<READING ATTEMPT: FAILED");
    }
  }
  void print(std::ostream& out,
    const DictionaryNode* nodes,
    size_t size)
  {
    out << size << '\n';
    for (size_t i = 0; i < size; ++i)
    {
      out << nodes[i] << '\n';
    }
  }
  std::string findCode(char key,
    const DictionaryNode* nodes,
    size_t size)
  {
    if (!key)
    {
      return "";
    }

    for (size_t i = 0; i < size; ++i)
    {
      if (nodes[i].key == key)
      {
        return nodes[i].code;
      }
    }
    throw std::logic_error("<NOT ENOUGH KEYS IN DICTIONARY>");
  }
  char findKey(std::string code,
    const DictionaryNode* nodes,
    size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      if (nodes[i].code == code)
      {
        return nodes[i].key;
      }
    }
    throw std::logic_error("<NO CODE FOUND>");
  }
}
