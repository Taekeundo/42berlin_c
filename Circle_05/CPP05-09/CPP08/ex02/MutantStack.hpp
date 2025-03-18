/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:44:02 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 15:44:03 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/* MACRO */
// Bold color definitions using ANSI for printing in the terminal.
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
// Basic
#include <iostream>   // std::cout, std::cerr
#include <stack>      // std::stack<T>
#include <deque>      // std::deque<int>

/* CLASS */
template <typename T>
class MutantStack : public std::stack<T>
{
  private:

  public:
    /* [ Orthodox Canonical Form ] */
    MutantStack() {}                                          // Default constructor
    ~MutantStack() {}                                         // Destructor
    MutantStack(const MutantStack& other) { *this = other; }  // Copy constructor
    MutantStack& operator=(const MutantStack& rhs)            // Overloaded assignment operator
    {
      if (this != &rhs)                 // Check for self-assignment: 자기 복사 방지
        std::stack<T>::operator=(rhs);  // std::stack의 대입 연산자 호출
      return *this;
    }

    /* [ Define user define iterator ]
      반복자 타입을 정의한다.
      4Types: iter, const iter, re-iter, const re-iter

      container_type
      = 보통은 "std::deque<int>"가 자동적으로 온다.
      = 굳이 container_type라고 써주는 이유: 어떤 타입의 컨테이너가 올 지 모르기 때문에.
      = std::stack<T>의 내부 컨테이너 타입이 std::deque<T>일 수도 있고, std::vector<T>일 수도 있기 때문.

      표준 컨테이너들은 기본적으로 4종류의 iterator를 제공(사용)한다.
        iterator                  read & write
        const_iterator            read only
        reverse_iterator          read & write  // Reverse order
        const_reverse_iterator    read only     // Reverse order
    */
    typedef typename std::stack<T>::container_type::iterator
      iterator;
    typedef typename std::stack<T>::container_type::const_iterator
      const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator
      reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

    /* [ begin, end function for each iterator ]
      C++98 version, available method, std::deque<T> supports
      = begin(), end(), rbegin(), rend() method.

      C++11 version, available method, std::deque<T> supports
      = cbegin(), cend(), crbegin(), crend()
      = In this project, i can't use C++11 version.

      What is 'c' of c.bgin() in below functions?
      = c는 std::stack<T> 클래스에서 상속(inherit) 받은 멤버
      = std::stack<T>의 protected멤버로 정의되어있다.
      = MutantStack클래스는 std::stack<T>를 상속받았기 때문에 c**에 접근할 수 있다.
    */
    iterator begin(void)
    {
      return this->c.begin();
    }

    iterator end(void)
    {
      return this->c.end();
    }

    const_iterator cbegin(void) const
    {
      return this->c.begin();
    }

    const_iterator cend(void) const
    {
      return this->c.end();
    }

    reverse_iterator rbegin(void)
    {
      return this->c.rbegin();
    }

    reverse_iterator rend(void)
    {
      return this->c.rend();
    }

    const_reverse_iterator crbegin(void) const
    {
      return this->c.rbegin();
    }

    const_reverse_iterator crend(void) const
    {
      return this->c.rend();
    }
};

#endif
