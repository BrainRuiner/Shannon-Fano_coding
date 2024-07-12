#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <stdexcept>
#include "utils.hpp"

namespace utils{
  template < class T, class Comp >
  T* quickSort(T* arr, size_t size, Comp comp);
  template < class T, class Comp >
  T* quickSort(T* arr, size_t start, size_t end, const Comp& comp);
  template < class T, class Comp >
  size_t partition(T* arr, size_t start, size_t end, Comp comp);

  template < class T, class Comp >
  T* quickSort(T* arr, size_t size, Comp comp){
    T* tmpArr = nullptr;
    try{
      tmpArr = new T[size]{};
      copyElements(tmpArr, arr, size);
      quickSort(tmpArr, 0, size - 1, comp);
      copyElements(arr, tmpArr, size);
      delete[] tmpArr;
      return arr;
    }
    catch (const std::bad_alloc&){
      throw std::logic_error("<INVALID SIZE>");
    }
    catch (...){
      delete[] tmpArr;
      throw;
    }
  }
  template < class T, class Comp >
  T* quickSort(T* arr, size_t start, size_t end, const Comp& comp){
    if (start < end){
      size_t p = partition(arr, start, end, comp);
      quickSort(arr, start, p, comp);
      quickSort(arr, p + 1, end, comp);
    }
    return arr;
  }
  template < class T, class Comp >
  size_t partition(T* arr, size_t start, size_t end, Comp comp){
    T pivot = arr[(start + end) / 2];
    size_t i = start;
    size_t j = end;
    while (true){
      while (comp(arr[i], pivot)){
        ++i;
      }
      while (comp(pivot, arr[j])){
        --j;
      }
      if (i >= j){
        return j;
      }
      swap(arr[i++], arr[j--]);
    }
  }
}

#endif
