/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:28 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:40:29 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* OCCF */
// 1. Default constructor
PresidentialPardonForm::PresidentialPardonForm()
: Form("Presidential pardon", 25, 5), mTarget("Unknown")
{}

// 2. Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// 3. Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
  *this = other;
}

// 4. Overloaded assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
        Form::operator=(rhs);
    return (*this);
}

// 5. Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: Form("Presidential pardon", 25, 5), mTarget(target) {}

/* Method */
/*

*/
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    checkExecution(executor);
    std::cout << "= <" << getName()
    << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}
