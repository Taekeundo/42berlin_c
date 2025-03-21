/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:43 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/21 10:57:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* OCCF */
// 1. Default constructor
Intern::Intern() {}

// 2. Destructor
Intern::~Intern() {}

// 3. Copy constructor
Intern::Intern(const Intern& other)
{
    *this = other;
}

// 4. Overloaded assignment operator
Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

// 5. Method
/*
    [ Role ]
    To creata a Form objec that matches the givin Param(1):'requestedFormType' & Param(2):'targetName'.

    [ Param ]
    Param(1): requestedFormType
    = 만들고자 하는 폼(form)의 종류를 나타내는 문자열

    Param(2): formTarget
    = 폼이 적용될 대상
    = ex) RobotomyRequestForm: 'targetName'(어떤 대상)에게 로봇화 수술요청을 하는 폼
          ShrubberyCreationForm: 'targetName'(특정 장소)에 나무를 심는 요청을 하는 폼
          PresidentialPardonForm: 'targetName'(특정 인물)을 대통령이 사면하는 요청을 하는 폼
    
    [ Logic ]
    1. Define available "formTypes"

    2. Check if the Param(1):"requestedFormtype" exists.

    3. Create the corresponding Form
        if a match is found
            -> creates the appropriate form based on the matched index.

        The form is returned as a dynamically allocated object by using [f] new.

    4. Exception handling (Try-catch)
        If the Param(1):"requestedFormtype" doesn't match with any form
            -> [f]NoTypeException is thrown.
            
        The exception is caught, and error messgae is printed, and return "nullptr".
*/
Form* Intern::makeForm(const std::string& requestedFormType, const std::string& formTarget)
{
    const std::string formTypes[FORM_TYPE_COUNT] =
    {
        "Robotomy request",
        "Shrubbery creation",
        "Presidential pardon"
    };

    try
    {
        for (int i = 0; i < FORM_TYPE_COUNT; ++i)
        {
            if (formTypes[i] == requestedFormType)
            {
                std::cout << PUR << "Intern" << EOC <<" try to make (" << requestedFormType
                        << ") for (" << formTarget << ")" << std::endl;
                switch (i)
                {
                    case 0:
                        return (new RobotomyRequestForm(formTarget));
                        break;
                    case 1:
                        return (new ShrubberyCreationForm(formTarget));
                        break;
                    case 2:
                        return (new PresidentialPardonForm(formTarget));
                        break;
                }
            }
        }
        // If not found,throw an exception.
        throw UnknownFormTypeException();
    }
    catch(const std::exception& e)
    {
        std::cerr << PUR << "Intern" << EOC << " cannot make (" << requestedFormType
                << ") for (" << formTarget << ")" << "\n" << "= Reason: "
                << RED << e.what() << EOC << std::endl;
        return NULL;
    }
}

// 6. Exceptional case
const char* Intern::UnknownFormTypeException::what(void) const throw()
{
    return ("requestedFormType is unknown.");
}
