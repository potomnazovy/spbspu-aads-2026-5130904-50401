#ifndef STACK_HPP
#define STACK_HPP
#include <cstddef>
#include <stdexcept>
#include "list.hpp"

namespace vasyakin
{
  template< class T >
  class Stack
  {
  public:
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    vasyakin::List< T > list_;
  };

  template< class T >
  void Stack< T >::push(const T& value)
  {
    list_.insert(list_.get_fake(), value);
  }

  template< class T >
  void Stack< T >::pop()
  {
    if (list_.get_size() == 0)
    {
      throw std::runtime_error ("Stack is empty");
    }
    list_.erase(list_.get_fake());
  }

  template< class T >
  bool Stack< T >::empty() const noexcept
  {
    return list_.get_size() == 0;
  }

  template< class T >
  T& Stack< T >::top()
  {
    if (list_.get_size() == 0)
    {
      throw std::runtime_error("Stack is empty");
    }
    return *list_.begin();
  }

  template< class T >
  const T& Stack< T >::top() const
  {
    if (list_.get_size() == 0)
    {
      throw std::runtime_error("Stack is empty");
    }
    return *list_.begin();
  }

  template< class T >
  size_t Stack< T >::size() const noexcept
  {
    return list_.get_size();
  }
}

#endif
