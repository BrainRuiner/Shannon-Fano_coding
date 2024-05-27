#ifndef MY_STRING_HPP
#define My_STRING_HPP

#include <cstring>

namespace mstr
{
  class MyString
  {
    public:
    MyString(const char* arr = nullptr, size_t = 0);
    MyString(const MyString& src);
    MyString(MyString&& src);
    ~MyString();

    MyString& operator=(const MyString& src);
    MyString& operator=(MyString&& src);
    MyString& operator=(const char* src);
    MyString& operator=(char src);
    MyString& operator+=(const MyString& src);
    MyString& operator+=(const char* src);
    MyString& operator+=(char src);


    char& operator[](size_t pos);
    char* arr();
    size_t size() const;
    size_t capacity() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend MyString operator+(const MyString& lhs, const char* rhs);
    friend MyString operator+(const MyString& lhs, char rhs);
    friend bool operator<(const MyString& lhs, const MyString& rhs);

    private:
    char* arr_;
    size_t size_;
    size_t capacity_;
  };
}
#endif
