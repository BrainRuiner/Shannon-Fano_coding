#include "myString.hpp"
#include <cstring>
#include "utils.hpp"

namespace mstr
{
  MyString::MyString(const char* arr, size_t size):
    arr_(nullptr),
    size_(size),
    capacity_(0)
  {
    if (size_)
    {
      capacity_ = size_ + 1;
      arr_ = new char[capacity_]{};
      utl::copyElements(arr_, arr, size_);
    }
  }
  MyString::MyString(const MyString& src):
    arr_(nullptr),
    size_(src.size_),
    capacity_(0)
  {
    if (size_)
    {
      capacity_ = size_ + 1;
      arr_ = new char[capacity_]{};
      utl::copyElements(arr_, src.arr_, size_);
    }
  }
  MyString::MyString(MyString&& src):
    arr_(src.arr_),
    size_(src.size_),
    capacity_(src.capacity_)
  {
    src.arr_ = nullptr;
    src.size_ = 0;
    src.capacity_ = 0;
  }
  MyString::~MyString()
  {
    delete[] arr_;
  }

  MyString& MyString::operator=(const MyString& src)
  {
    if (this != &src)
    {
      size_ = src.size_;
      delete[] arr_;
      arr_ = nullptr;
      capacity_ = 0;
      if (size_)
      {
        capacity_ = src.capacity_;
        arr_ = new char[capacity_]{};
        utl::copyElements(arr_, src.arr_, size_);
      }
    }
    return *this;
  }
  MyString& MyString::operator=(MyString&& src)
  {
    if (this != &src)
    {
      arr_ = src.arr_;
      size_ = src.size_;
      capacity_ = src.capacity_;
      src.arr_ = nullptr;
      src.size_ = 0;
      src.capacity_ = 0;
    }
    return *this;
  }
  MyString& MyString::operator=(const char* src)
  {
    size_t i = 0;
    for (; src[i] != '\0'; ++i);
    size_ = i;
    delete[] arr_;
    arr_ = nullptr;
    capacity_ = 0;
    if (size_)
    {
      capacity_ = size_ + 1;
      arr_ = new char[capacity_]{};
      utl::copyElements(arr_, src, size_);
    }
    return *this;
  }
  MyString& MyString::operator=(char src)
  {
    size_ = 1;
    delete[] arr_;
    capacity_ = size_ + 1;
    arr_ = new char[capacity_]{};
    arr_[0] = src;
    return *this;
  }
  MyString& MyString::operator+=(const MyString& src)
  {
    size_ = size_ + src.size_;
    delete[] arr_;
    arr_ = nullptr;
    capacity_ = 0;
    if (size_)
    {
      capacity_ = size_ + 1;
      arr_ = new char[capacity_]{};
      std::strcat(arr_, src.arr_);
    }
    return *this;
  }
  MyString& MyString::operator+=(const char* src)
  {
    size_t i = 0;
    for (; src[i] != '\0'; ++i);
    size_ = size_ + i;
    delete[] arr_;
    arr_ = nullptr;
    capacity_ = 0;
    if (size_)
    {
      capacity_ = size_ + 1;
      arr_ = new char[capacity_]{};
      std::strcat(arr_, src);
    }
    return *this;
  }
  MyString& MyString::operator+=(char src)
  {
    if (size_ + 1 >= capacity_)
    {
      char* tmp = new char[++capacity_]{};
      utl::copyElements(tmp, arr_, size_);
      utl::swap(arr_, tmp);
      delete[] tmp;
    }
    arr_[size_++] = src;
    return *this;
  }

  char& MyString::operator[](size_t pos)
  {
    return arr_[pos];
  }
  char* MyString::arr()
  {
    return arr_;
  }
  size_t MyString::size() const
  {
    return size_;
  }
  size_t MyString::capacity() const
  {
    return capacity_;
  }

  MyString operator+(const MyString& lhs, const MyString& rhs)
  {
    size_t size = lhs.size() + rhs.size();
    size_t capacity = size + 1;
    char* tmp = new char[capacity]{};
    utl::copyElements(tmp, lhs.arr_, lhs.size_);
    std::strcat(tmp, rhs.arr_);
    MyString dest(tmp, size);
    delete[] tmp;
    return dest;
  }
  MyString operator+(const MyString& lhs, const char* rhs)
  {
    size_t i = 0;
    for (; rhs[i] != '\0'; ++i);
    size_t size = lhs.size_ + i;
    size_t capacity = size + 1;
    char* tmp = new char[capacity]{};
    utl::copyElements(tmp, lhs.arr_, lhs.size_);
    std::strcat(tmp, rhs);
    MyString dest(tmp, size);
    delete[] tmp;
    return dest;
  }
  MyString operator+(const MyString& lhs, char src)
  {
    size_t size = lhs.size_ + 1;
    size_t capacity = size + 1;
    char* tmp = new char[capacity]{};
    utl::copyElements(tmp, lhs.arr_, lhs.size_);
    tmp[size] = src;
    MyString dest(tmp, size);
    delete[] tmp;
    return dest;
  }
  bool operator<(const MyString& lhs, const MyString& rhs)
  {
    return (std::strcmp(lhs.arr_, rhs.arr_) < 0);
  }
}
