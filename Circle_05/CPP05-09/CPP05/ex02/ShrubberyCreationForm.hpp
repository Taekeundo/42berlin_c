/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:47 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:41:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/* HEADER FILE */
// Basic
#include <fstream>  // For reading a form and writing to the files. (= ofstream)

#include "Form.hpp"

/* CLASS */
/*
    Every logic & content is same with RobotomyRequest class.
    Only [f]execute, inherited from "Form" class is different.
*/
class ShrubberyCreationForm : public Form
{
    private:
        std::string const mTarget;

    public:
        // OCCF: 5ea
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ShrubberyCreationForm(const std::string& target);
        
        // Method: 1ea
        void execute(const Bureaucrat& executor) const;
};

#endif
