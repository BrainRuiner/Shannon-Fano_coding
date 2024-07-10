#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils
{
  template< class T >
  void swap(T& a, T& b);
  template< class T >
  T* copyElements
  (
    T* dest,
    const T* src,
    size_t size
  );

  template< class T >
  void swap(T& a, T& b)
  {
    T tmp = a;
    a = b;
    b = tmp;
  }
  template< class T >
  T* copyElements(T* dest, const T* src, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      dest[i] = src[i];
    }
    return dest;
  }
}
#endif
