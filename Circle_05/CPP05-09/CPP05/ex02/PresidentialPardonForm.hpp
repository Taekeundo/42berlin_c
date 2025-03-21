/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:21 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:40:30 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/* HEADER FILE */
#include "Form.hpp"

/* CLASS */
/*
    Every logic & content is same with RobotomyRequest class.
    Only [f]execute, inherited from "Form" class is different.
*/
class PresidentialPardonForm : public Form
{
    private:
        std::string const mTarget;

    public:
        // OCCF: 5ea
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        PresidentialPardonForm(const std::string& target);
        
        // Method: 1ea
        void execute(const Bureaucrat& executor) const;
};

#endif
