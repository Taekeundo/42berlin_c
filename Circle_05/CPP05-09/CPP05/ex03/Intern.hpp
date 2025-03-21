/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:46 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/21 10:57:47 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

/* MACRO */
#define FORM_TYPE_COUNT 3

/* HEADER FILE */
// Basic
#include <string>     // std::string

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        /* OCCF */
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& rhs);

        /* Method */
        Form* makeForm(const std::string& requestedFormType, const std::string& targetName);

        /* Handling exception */
        class UnknownFormTypeException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };
};

#endif
