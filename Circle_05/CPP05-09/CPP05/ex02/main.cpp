/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:35 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:41:36 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
  // 1. Make "Bureaucrat" & "Form object"
  Bureaucrat b1("Jason", 6);
  Bureaucrat b2("Hongpei", 4);
  Bureaucrat b3("Arthur", 6);
  
  // 2. Check, if objects are made well.
  std::cout << BLU << "\n[ Test1 ] Bureaucrat" << EOC << std::endl;
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << std::endl << std::endl << std::endl;



  // 3. Make "RobotomyRequestForm" object.
  Form *robotomy = new RobotomyRequestForm("TargetForRobotomy");

  // 4. Check "Jason" can execute "robotomy" form.
  std::cout << BLU << "[ Test2 ] executeForm for 'robotomy' <" << b1.getName() << ">"<< EOC << std::endl;
  b1.executeForm(*robotomy);
  std::cout << std::endl;

  std::cout << BLU << "[ Test2 ] signForm for 'robotomy' <" << b1.getName() << ">" << EOC << std::endl;
  b1.signForm(*robotomy);
  std::cout << std::endl;

  std::cout << BLU << "[ Test2 ] executeForm again for 'robotomy' <" << b1.getName() << ">" << EOC << std::endl;
  b1.executeForm(*robotomy);
  std::cout << std::endl << std::endl << std::endl;



  // 5. Make "ShrubberyCreationForm" object.
  Form *shrubbery = new ShrubberyCreationForm("TargetForShrubbery");

  // 6. Check "Jason" can execute "shrubbery" form.
  std::cout << BLU << "[ Test3 ] executeForm for 'shrubbery' <" << b2.getName() << ">"<< EOC << std::endl;
  b2.executeForm(*shrubbery);
  std::cout << std::endl;

  std::cout << BLU << "[ Test3 ] signForm for 'shrubbery' <" << b2.getName() << ">" << EOC << std::endl;
  b2.signForm(*shrubbery);
  std::cout << std::endl;

  std::cout << BLU << "[ Test3 ] executeForm again for 'shrubbery' <" << b2.getName() << ">" << EOC << std::endl;
  b2.executeForm(*shrubbery);
  std::cout << std::endl << std::endl << std::endl;



  // 7. Make "PresidentialPardonForm" object.
  Form *presidential = new PresidentialPardonForm("TargetForPresidentailPardon");

  // 8. Check "Jason" can execute "presidential" form.
  std::cout << BLU << "[ Test4 ] executeForm for 'presidential' <" << b3.getName() << ">"<< EOC << std::endl;
  b3.executeForm(*presidential);
  std::cout << std::endl;

  std::cout << BLU << "[ Test4 ] signForm for 'presidential' <" << b3.getName() << ">" << EOC << std::endl;
  b3.signForm(*presidential);
  std::cout << std::endl;

  std::cout << BLU << "[ Test4 ] executeForm again for 'presidential' <" << b3.getName() << ">" << EOC << std::endl;
  b3.executeForm(*presidential);
  std::cout << std::endl;

  std::cout << BLU << "\t[ Test4-1 ] [f]increaseGrade for 'presidential' <" << b3.getName() << ">" << EOC << std::endl;
  std::cout << RED << "\t[ Test4-1 ] Before: " << EOC << b3 << std::endl;
  try
  {
    b3.increaseGrade();
    std::cout << GRE << "\t\t[ Test4-1 ] Success to [f]increaseGrade" << EOC << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << RED << "\t[ Test4-1 ] After: " << EOC << b3 << std::endl << std::endl;

  std::cout << BLU << "[ Test4 ] executeForm again again for 'presidential' <" << b3.getName() << ">" << EOC << std::endl;
  b3.executeForm(*presidential);
  std::cout << std::endl;
  
  delete (presidential);
  delete (shrubbery);
  delete (robotomy);
  return 0;
}
