/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:35:16 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:35:18 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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
#include <string>     // std::string
#include <iostream>   // std::cout, std::cerr

// Exceptional case
#include <exception>  // std::exception

// Following the PDF instruction.
#define HIGHESTGRADE 1
#define LOWESTGRADE  150

/* CLASS */
class Bureaucrat
{
  private:
    const std::string mName;
    int mGrade;

  public:
    /* [ OCCF: Orthodox Canonical Class Form ] */
    Bureaucrat();                                           // Default constructor
    ~Bureaucrat();                                          // Destructor
    Bureaucrat(const Bureaucrat& other);                    // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& rhs);           // Overloaded assignment operator
    Bureaucrat(const std::string& name, const int& grade);  // Parameterized constructor

    /* [ Methods ] */
    /*  Getter
        1st 'const'
        = Impossible to fix
        = It's never happen that information from 'getter' is changed.
          So put 'const' for the Getter's return.

        2nd 'const'
        = const member function
        = "이 함수가 객체의 상태를 수정하지 않겠다는 보장을 하기 위해"
        = 함수를 안전하게 사용할 수 있게 하기 위해.
    */
    const std::string& getName() const { return (mName); }
    const int& getGrade() const { return (mGrade); }

    // Increase, decrease grade
    int& increaseGrade();
    int& decreaseGrade();

    /* [ Custom class for exceptional cases ] */
    // Should i put 'virtual' for what(), which is inherited by std::exception?
    // No: what() is already declared "virtual const char*" in std::exception.s
    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif
