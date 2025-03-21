/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:32 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:40:33 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* OCCF */
// 1. Default constructor
RobotomyRequestForm::RobotomyRequestForm()
: Form("Robotomy request", 72, 45), mTarget("Unknown")
{}

// 2. Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// 3. Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
  *this = other;
}

// 4. Overloaded assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
  if (this != &rhs)
    Form::operator=(rhs);
  return (*this);
}

// 5. Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: Form("Robotomy request", 72, 45), mTarget(target) {}

/* Method */
/*
  [ Goal ]
  50% chance to transform Param(1):executor into a robot.
  = 50%확률로 Param(1):executor을 로봇으로 개조한다.

  [ Logic ]
  1. Check the authority, whether Param(1) can execute the 'Form'.
      Not everyone can execute this RobotomyRequestForm,
      only officials with the authority to sign and execute it can do so.
      = So first check, whether executor has the authority.

  2. Generate the '0' or '1' randomly by using the [f] rand() % 2
     to check whether the robotization is successful of not.

    (Success)
    = if '1' -> Param(1) is now robot.

    (Fail)
    = if '0' -> Param(1) isn't robot.

  3. Print the result.
*/
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
  int robotization;

  checkExecution(executor);
  std::srand(static_cast<unsigned int>(std::time(0)));
  std::cout << PUR << "!! 50% chance !!" << EOC << std::endl;
  robotization = rand() % 2;
  if (robotization)
  {
    std::cout << "= <" << mTarget << ">" << GRE << " succeeded"
              << EOC << " to be robotomized" << std::endl
              << YEL << "= [ SOUND ] Drill!! Drill!!" << EOC << std::endl;
  }
  else
  {
    std::cout << "= <" << mTarget << ">" << RED << " failed"
              << EOC << " to be robotomized" << std::endl;
  }
}
