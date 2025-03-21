/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:39 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:40:40 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* OCCF */
// 1. Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: Form("Shrubbery creation", 145, 137), mTarget("Unknown")
{}

// 2. Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// 3. Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
  *this = other;
}

// 4. Overloaded assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
        Form::operator=(rhs);
    return (*this);
}

// 5. Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: Form("Shrubbery creation", 145, 137), mTarget(target) {}

/* Method */
/*

*/
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    std::ofstream   file;

    checkExecution(executor);
    file.open(("<" + mTarget + ">_Shrubbery").c_str());
    if (!file.good())
        throw FailToOpenFileException();
    std::string testShrubbery = "   v .   ._, |_  .,             \n"
                                "   `-._\\/  .  \\ /    |/_      \n"
                                "       \\  _\\, y | \\//        \n"
                                " _\\_.___\\, \\/ -.\\||         \n"
                                "   `7-,--.`._||  / / ,          \n"
                                "   /'     `-. `./ / |/_.'       \n"
                                "             |    |//           \n"
                                "             |_    /            \n"
                                "             |-   |             \n"
                                "             |   =|             \n"
                                "             |    |             \n"
                                "------------/ ,  . \\--------._ \n";
    file << testShrubbery;
    file.close();
}
