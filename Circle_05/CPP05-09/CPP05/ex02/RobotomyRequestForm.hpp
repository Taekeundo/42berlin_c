/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:35 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:40:36 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

/* HEADER FILE */
// Basic
#include <string>     // std::string
#include <iostream>   // std::cout, std::cerr
#include <cstdlib>    // rand(), srand()  -> [f]execute
#include <ctime>      // std::time()      -> [f]execute

#include "Form.hpp"   // For ex02, 'Form' class is 'Abstract class'.

class RobotomyRequestForm : public Form
{
  private:
    std::string const mTarget;

  public:
    // OCCF
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    RobotomyRequestForm(const std::string& target);

    // Method
    void execute(const Bureaucrat& executor) const;
};

#endif
