/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:39:56 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/21 10:57:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

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

// Bureaucrat.hpp
#include "Bureaucrat.hpp"

/* Class */
class Form
{
    private:
        const std::string mName;
        const int signGrade;
        const int execGrade;
        bool isSigned;
    
    public:
        // OCCF: 5ea
        Form();                             // Default constructor
        Form(const Form& other);            // Copy constructor
        Form& operator=(const Form& rhs);   // Overloaded assignment operator
        Form(const std::string& name,
                const int& signGrade,
                const int& execGrade);      // Parameterized constructor
        virtual ~Form();                    // Destructor
                                            // For using [f] delete, Abstract class's destructor must be virtual.
    
        // Getter: 4ea
        const std::string& getName() const;
        const int& getSignGrade() const;
        const int& getExecGrade() const;
        const bool& getIsSigned() const;

        // Methods: 2ea
        void beSigned(const Bureaucrat& signingBureaucrat);
        void checkExecution(const Bureaucrat& executingBureaucrat) const;

        // Virtual: 1ea
        /*
        In "Form" class, don't use [f]execute directly -> Abstract.
        But in "RobotomyRequestForm" class, which is inherited by the "Form"class,
        use the [f]execute directly.
        Here in the "Form" class, We call the [f]execute, <pure virtual function>.
        = 부모 class에 굳이 pure virtual function을 선언해주는 이유: 다형성
          어떤 자식에게는 execute라는 함수가 로봇화를 위해 사용될수 있지만
          따른 자식class에게는 해당 함수가 다른 로직을 구현하는데 사용 될 수 있다.
          각각의 자식class가 동일한 이름의 함수를 사용하게 하고,
          한꺼번에 부모 클래스에서 컨트롤 할 수 있어서 관리에 용이하다.
        
        Pure virtual function must put "= 0;", when we declare the function in class.

        Pure virtual function을 하나라도 갖고 있는 추상 클래스(abstract class)의 경우,
        **delete**를 호출하기 위해서는 반드시 소멸자(destructor)를 virtual로 작성해야 합니다.
        */
        virtual void execute(const Bureaucrat& executor) const = 0;

        // Exception: 4ea
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

        class NotSignedException : public std::exception
        {
            const char* what() const throw();
        };

        class FailToOpenFileException : public std::exception
        {
            const char* what() const throw();
        };
};
    
std::ostream& operator<<(std::ostream& o, const Form& target);

#endif
