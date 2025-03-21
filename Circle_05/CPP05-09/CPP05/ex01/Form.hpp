/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:38:03 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:38:04 by tkwak            ###   ########.fr       */
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
        ~Form();                            // Destructor                                                                    
        Form(const Form& other);            // Copy constructor
        Form& operator=(const Form& rhs);   // Overloaded assignment operator
        Form(const std::string& name,
                const int& signGrade,
                const int& execGrade);      // Parameterized constructor
    
        // Getter: 4ea
        const std::string& getName() const;
        const int& getSignGrade() const;
        const int& getExecGrade() const;
        const bool& getIsSigned() const;

        // Sign: 1ea
        void beSigned(const Bureaucrat& signingBureaucrat);

        // Exception: 2ea
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};
    
std::ostream& operator<<(std::ostream& o, const Form& target);

#endif
