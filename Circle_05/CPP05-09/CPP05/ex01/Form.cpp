/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:38:01 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:38:01 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* OCCF: 5ea */
// 1. Default constructor
Form::Form() : mName("Default"), signGrade(150), execGrade(150), isSigned(false) {}

// 2. Destructor
Form::~Form() {}

// 3. Copy constructor
Form::Form(const Form& other) : mName(other.getName()),
                                signGrade(other.getSignGrade()),
                                execGrade(other.getExecGrade()),
                                isSigned(false)
{
    if (signGrade < HIGHESTGRADE || execGrade < HIGHESTGRADE)
        throw GradeTooHighException();
    if (signGrade > LOWESTGRADE || execGrade > LOWESTGRADE)
        throw GradeTooLowException();
}

// 4. Overloaded assignment operator
Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
    {
        if (rhs.getSignGrade() < HIGHESTGRADE || rhs.getExecGrade() < HIGHESTGRADE)
            throw GradeTooHighException();
        if (rhs.getSignGrade() > LOWESTGRADE || rhs.getExecGrade() > LOWESTGRADE)
            throw GradeTooLowException();
        const_cast<std::string&>(mName) = rhs.getName();
        const_cast<int&>(signGrade) = rhs.getSignGrade();
        const_cast<int&>(execGrade) = rhs.getExecGrade();
        isSigned = rhs.getIsSigned();
    }
    return (*this);
}

// 5. Parameterized constructor
Form::Form(const std::string& newName,
            const int& newSignGrade,
            const int& newExecGrade)
: mName(newName), signGrade(newSignGrade), execGrade(newExecGrade), isSigned(false)
{
    if (signGrade < HIGHESTGRADE || execGrade < HIGHESTGRADE)
        throw GradeTooHighException();
    if (signGrade > LOWESTGRADE || execGrade > LOWESTGRADE)
        throw GradeTooLowException();
}

// ---------------------------------------------------------------------- //

/* Getter: 4ea */
const std::string&  Form::getName(void) const
{
    return (mName);
}
  
const int&  Form::getSignGrade(void) const
{
    return (signGrade);
}

const int&  Form::getExecGrade(void) const
{
    return (execGrade);
}

const bool& Form::getIsSigned(void) const
{
    return (isSigned);
}

// ---------------------------------------------------------------------- //

/* Sign: 1ea */
void Form::beSigned(const Bureaucrat& signingBureaucrat)
{
    if (signingBureaucrat.getGrade() <= signGrade)
    {
        isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

// ---------------------------------------------------------------------- //

/* Exception: 2ea */
const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too High");
}
  
const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

// ---------------------------------------------------------------------- //

/* Overloading operator '<<' */
std::ostream& operator<<(std::ostream& o, const Form& target)
{
    return (o << "<" << target.getName() << ">, sign grade <"
            << target.getSignGrade() << ">, exec grade <"
            << target.getExecGrade() << ">, signed <"
            << std::boolalpha << target.getIsSigned() << ">");
}
