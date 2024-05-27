#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include "Queue.hpp"
#include <exception>

namespace qarExc
{
  class QueueOverflow: public std::exception
  {
    public:
    char const* what() const noexcept override
    {
      return "Queue Overflow";
    }
  };
  class QueueUnderflow: public std::exception
  {
    public:
    char const* what() const noexcept override
    {
      return "Queue Underflow";
    }
  };
  class WrongQueueSize: public std::exception
  {
    public:
    char const* what() const noexcept override
    {
      return "Queue wrong size";
    }
  };
}

namespace qar
{
  template < class T >
  class QueueArray: public que::Queue< T >
  {
    public:
    QueueArray(int size = 100);
    QueueArray(const QueueArray& src);
    QueueArray(QueueArray&& src);
    virtual ~QueueArray();
    QueueArray< T >& operator=(const QueueArray& src);
    QueueArray< T >& operator=(QueueArray&& src);

    void enQueue(const T& e);
    T deQueue();
    bool isEmpty();
    private:
    T* array_;
    int head_;
    int tail_;
    int size_;

    bool isFull();
    void swap(QueueArray& src);
  };
}
template < class T >
qar::QueueArray< T >::QueueArray(int size):
  array_(nullptr),
  head_(-1),
  tail_(-1),
  size_(size)
{
  if (size == 0)
  {
    throw qarExc::WrongQueueSize();
  }
  try
  {
    array_ = new T[size];
  }
  catch (...)
  {
    throw qarExc::WrongQueueSize();
  }
}
template < class T >
qar::QueueArray< T >::QueueArray(const QueueArray& src):
  array_(nullptr),
  head_(src.head_),
  tail_(src.tail_),
  size_(src.size_)
{
  try
  {
    array_ = new T[src.size_];
    for (int i = 0; i < src.size_; ++i)
    {
      array_[i] = src.array_[i];
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete array_;
    throw e;
  }
}
template < class T >
qar::QueueArray< T >::QueueArray(QueueArray&& src):
  array_(nullptr),
  head_(src.head_),
  tail_(src.tail_),
  size_(src.size_)
{
  src.array_ = nullptr;
  src.head_ = -1;
  src.tail_ = -1;
  src.size_ = 0;
}
template < class T >
qar::QueueArray< T >::~QueueArray()
{
  delete[] array_;
}
template < class T >
qar::QueueArray< T >& qar::QueueArray< T >::operator=(const QueueArray& src)
{
  QueueArray< T > tmp(src);
  swap(tmp);
  return *this;
}
template < class T >
qar::QueueArray< T >& qar::QueueArray< T >::operator=(QueueArray&& src)
{
  array_ = src.array_;
  head_ = src.head_;
  tail_ = src.tail_;
  size_ = src.size_;

  src.array_ = nullptr;
  src.head_ = -1;
  src.tail_ = -1;
  src.size_ = 0;
}
template < class T >
void qar::QueueArray< T >::enQueue(const T& e)
{
  if (isEmpty())
  {
    head_ = 0;
    tail_ = 0;
    array_[0] = e;
    return;
  }

  if (isFull())
  {
    throw qarExc::QueueOverflow();
  }

  tail_ = (tail_ + 1) % size_;
  array_[tail_] = e;
}
template < class T >
T qar::QueueArray< T >::deQueue()
{
  if (isEmpty())
  {
    throw qarExc::QueueUnderflow();
  }

  T tmp(array_[head_]);
  if (head_ != tail_)
  {
    head_ = (head_ + 1) % size_;
  }
  else
  {
    head_ = -1;
    tail_ = -1;
  }
  return tmp;
}
template < class T >
bool qar::QueueArray< T >::isEmpty()
{
  return head_ == -1 && tail_ == -1;
}
template < class T >
bool qar::QueueArray< T >::isFull()
{
  return (head_ - tail_ == 1) || (head_ == 0 && tail_ == size_ - 1);
}
template < class T >
void qar::QueueArray< T >::swap(QueueArray& src)
{
  std::swap(array_, src.array_);
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
  std::swap(size_, src.size_);
}

#endif
