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
#include "Intern.hpp"

int main()
{
  Intern intern;
  
  // 1. Make "Bureaucrat" & "Form object"
  Bureaucrat b1("Jason", 100);
  Bureaucrat b2("Hongpei", 50);
  Bureaucrat b3("Arthur", 1);
  
  // 2. Check, if objects are made well.
  std::cout << BLU << "\n[ Test1 ] Bureaucrat" << EOC << std::endl;
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << std::endl;

  // 3. Declare 3type of forms, not assign yet.
  //                            Name              sign    execute
  Form *form1 = NULL; // "Robotomy request"       72       45
  Form *form2 = NULL; // "Shrubbery creation"     145      137
  Form *form3 = NULL; // "Presidential pardon"    25       5
  Form *form4 = NULL; // "TEST"

  // 4. Intern makes 4types of Form.
  // 4-1. Robotomy
  std::cout << BLU << "\n[ Test2 ] [f]intern.makeForm" << EOC << std::endl;
  try
  {
    form1 = intern.makeForm("Robotomy request", "target1");
    std::cout << "= Form" << GRE << "(" << form1->getName() << ")" <<  EOC << " is created" << std::endl << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  // 4-2. Shrubbery
  try
  {
    form2 = intern.makeForm("Shrubbery creation", "target2");
    std::cout << "= Form" << GRE << "(" << form2->getName() << ")" <<  EOC << " is created" << std::endl << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  // 4-3. Presidential
  try
  {
    form3 = intern.makeForm("Presidential pardon", "target3");
    std::cout << "= Form" << GRE << "(" << form3->getName() << ")" <<  EOC << " is created" << std::endl << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  // 4-4. Not allowed(Random)type form
  try
  {
    form4 = intern.makeForm("Random type", "target4");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;

  // 4-5. If any form(1,2,3) can't be made, terminate the program.
  if (!form1 || !form2 || !form3)
  {
    delete (form3);
    delete (form2);
    delete (form1);
    return (1);
  }

  // 5. Check form's info.
  std::cout << BLU << "\n[ Test3 ] Check whether the form was created from [f]makeForm" << EOC << std::endl;
  std::cout << *form1 << std::endl;
  std::cout << *form2 << std::endl;
  std::cout << *form3 << std::endl;
  std::cout << std::endl;

  // 6. Check [f]signForm for 3 types of form.
  std::cout << BLU << "\n[ Test4 ] Check [f]signForm" << EOC << std::endl;
  // 6-0. Show 3 worker's grade
  std::cout << PUR << "[Grade]" << std::endl;
  std::cout << PUR << "Jason:   " << b1.getGrade() << std::endl;
  std::cout << PUR << "Hongpei: " << b2.getGrade() << std::endl;
  std::cout << PUR << "Arthur:  " << b3.getGrade() << std::endl << std::endl;

  // 6-1. form1
  std::cout << YEL << "form1: " << form1->getSignGrade() << EOC << std::endl;
  b1.signForm(*form1);
  b2.signForm(*form1);
  b3.signForm(*form1);
  std::cout << std::endl;

  // 6-2. form2
  std::cout << YEL << "form2: " << form2->getSignGrade() << EOC << std::endl;
  b1.signForm(*form2);
  b2.signForm(*form2);
  b3.signForm(*form2);
  std::cout << std::endl;

  // 6-3. form3
  std::cout << YEL << "form3: " << form3->getSignGrade() << EOC << std::endl;
  b1.signForm(*form3);
  b2.signForm(*form3);
  b3.signForm(*form3);
  std::cout << std::endl;

  // 7. Check [f]executeForm
  std::cout << BLU << "\n[ Test5 ] Check [f]executeForm" << EOC << std::endl;
  // 7-1. form1
  std::cout << YEL << "form1: " << form1->getName() << EOC << std::endl;
  b1.executeForm(*form1);
  b2.executeForm(*form1);
  b3.executeForm(*form1);
  std::cout << std::endl;

  // 7-2. form2
  std::cout << YEL << "form2: " << form2->getName() << EOC << std::endl;
  b1.executeForm(*form2);
  b2.executeForm(*form2);
  b3.executeForm(*form2);
  std::cout << std::endl;

  // 7-3. form3
  std::cout << YEL << "form3: " << form3->getName() << EOC << std::endl;
  b1.executeForm(*form3);
  b2.executeForm(*form3);
  b3.executeForm(*form3);
  std::cout << std::endl;

  // 8. delete memory before exit.
  delete (form3);
  delete (form2);
  delete (form1);
  return 0;
}
