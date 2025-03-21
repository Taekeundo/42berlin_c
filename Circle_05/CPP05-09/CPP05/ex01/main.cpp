/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:38:07 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:38:07 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  // 1. Make "Bureaucrat" & "Form object"
  Bureaucrat b1("Jason", 6);
  Form f1("WBS", 5, 5);
  
  // 2. Check, if objects are made well.
  std::cout << BLU << "\n[ Print ] Bureaucrat & Form" << EOC << std::endl;
  std::cout << b1 << std::endl;
  std::cout << f1 << std::endl;
  std::cout << std::endl;

  // 3. Test [f]signForm
  std::cout << BLU << "[ TEST ] [f]signForm ]" << EOC << std::endl;
  std::cout << "Can " << PUR << b1.getName() << EOC << " sign for " << PUR << f1.getName() << EOC << "?" << std::endl;
  b1.signForm(f1);
  std::cout << std::endl;

  // 4. Test [f]signForm after [f]increaseGrade.
  std::cout << BLU << "[ TEST ] [f]signForm agin after [f]increaseGrade ]" << EOC << std::endl;
  std::cout << "Before [f]increaseGrade: " << b1 << std::endl;
  b1.increaseGrade();
  std::cout << "After [f]increaseGrade: " << b1 << std::endl;
  std::cout << "Try one more time [f]signForm." << std::endl;
  b1.signForm(f1);
  std::cout << std::endl;

  return 0;
}
