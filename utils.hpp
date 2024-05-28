#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdexcept>

namespace utl
{
  struct Node
  {
    char symbol = 0;
    size_t quantity = 0;
    std::string code = "";
  };
  Node* getNode(Node*& set, size_t& size, const std::string& src);

  template< class T, class Comp >
  T* quickSort(T* arr, size_t size, Comp comp);
  template< class T, class Comp >
  T* quickSort(T* arr, size_t start, size_t end, const Comp& comp);
  template< class T >
  void swap(T& a, T& b);
  template< class T >
  T* copyElements(T* dest, const T* src, size_t size);
}

template< class T, class Comp >
T* utl::quickSort(T* arr, size_t size, Comp comp)
{
  T* tmpArr = nullptr;
  try
  {
    tmpArr = new T[size]{};
    copyElements(tmpArr, arr, size);
    quickSort(tmpArr, 0, size - 1, comp);
    return copyElements(arr, tmpArr, size);
  }
  catch (const std::bad_alloc&)
  {
    throw std::logic_error("<INVALID SIZE>");
  }
  catch (...)
  {
    throw;
  }
}
template< class T, class Comp >
T* utl::quickSort(T* arr, size_t start, size_t end, const Comp& comp)
{
  if (start < end)
  {
    T pivot = arr[end];
    size_t i = (start - 1);
    for (size_t j = start; j < end; j++)
    {
      if (comp(arr[j], pivot))
      {
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i + 1], arr[end]);
    size_t pi = i + 1;

    quickSort(arr, start, pi - 1, comp);
    quickSort(arr, pi + 1, end, comp);
  }
  return arr;
}
template< class T >
void utl::swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}
template< class T >
T* utl::copyElements(T* dest, const T* src, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    dest[i] = src[i];
  }
  return dest;
}

#endif
