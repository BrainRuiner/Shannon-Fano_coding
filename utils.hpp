#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdexcept>

namespace utl
{
  struct Node
  {
    char symbol;
    size_t quantity;
  };
  bool isLessQuantity(const Node& n1, const Node& n2);
  Node* sortByQuantity(Node* nodes, size_t size);

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
  if (start >= end)
  {
    return arr;
  }
  size_t left = start;
  size_t right = end;
  T pivot = arr[(right - left) / 2];
  while (left <= right)
  {
    while (comp(arr[left], pivot))
    {
      ++left;
    }
    while (comp(pivot, arr[right]))
    {
      --right;
    }
    if (left <= right)
    {
      swap(arr[left], arr[right]);
      ++left;
      --right;
    }
  }
  quickSort(arr, start, right, comp);
  quickSort(arr, left, end, comp);
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
