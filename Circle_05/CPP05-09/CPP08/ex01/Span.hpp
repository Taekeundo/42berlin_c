/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:43:20 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 15:43:20 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/* MACRO */
// Bold color definitions using ANSI
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
#include <limits>     // std::numeric_limits
#include <vector>     // std::vector<int>

// Algorithm
#include <algorithm>  // std::find

// Exceptional case
#include <stdexcept>  // std::runtime_error, std::exception

/* CLASS */
/*
  [ Definition ]
  Save the array, consist of integer type,
  provides the function to find the minimum and maximum difference.
  = 정수 배열을 저장하고,
    최소 및 최대 차이(Shortest/Longest Span)를 구하는 기능을 제공하는 클래스.

  [ Mandatory function ]
  1. Add number
  2. shortestSpan()
  3. longestSpan()
  4. Handle exceptional case
    = Must be at least 2 elements to calculate the Span.
    = [c]CapacityExceededException, [c]InsufficientElementsException
  
  [ Memo ]
  maxCapacity's type is 'const'
  = must be initialized in the initializer list
  = Can not assign to const members in the constructor body.
*/
class Span
{
  private:
    unsigned const int  maxCapacity;    // Maximum capacity of the Span (limit for number of integers)
    std::vector<int> vectorContainer;   // A vector to store integer type values.

  public:
    /* [ OCCF: Orthodox Canonical Class Form ] */
    Span();                             // Default constructor
    Span(unsigned int value);           // Parameterized constructor
    Span(const Span& other);            // Copy constructor
    Span& operator=(const Span& rhs);   // Overloaded assignment operator
    ~Span();                            // Destructor

    /* [ Methods for adding values ] */
    void addNumber(int value);                    // Add a single integer value to the Span
    void addRange(std::vector<int> vectorRange);  // Add a range of values (from a vector) to the Span

    /* [ Methods for calculating spans ] */
    unsigned int  shortestSpan();         // Find the shortest span between two elements.
    unsigned int  longestSpan();          // Find the longest span between two elements.

    /* [ Custom class for exceptional cases ] */
    // Should i put 'virtual' for what(), which is inherited by std::exception?
    // No: what() is already declared "virtual const char*" in std::exception.s

    // 1. Not enough elelments
    class InsufficientElementsException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    // 2. Capacity is exceeded
    class CapacityExceededException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};

#endif
