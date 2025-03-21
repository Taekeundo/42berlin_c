/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:35:20 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:35:21 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
  [ Background ]
  1. Inlinde declaration vs hpp + cpp declaration
    함수 선언 방식의 차이.

    a. 인라인 선언 (헤더에서 직접 정의)
      간단한 코드의 경우 인라인이 더 빠르다.

    b. 헤더 선언 + CPP정의
      코드 분리로 가독성이 좋다.
      규모가 크고 유지보수가 중요하다면 이 방식이 좋다.
*/
int main()
{
  // 1. Make 4 objects
  Bureaucrat b1("Jason", 1);
  Bureaucrat b2("Hongpei", 2);
  Bureaucrat b3("Arthur", 3);
  Bureaucrat b4("Taka", 150);

  // 2. Check, if objects is made
  std::cout << BLU << "\n[ Print ] Objects" << EOC << std::endl;
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << b4 << std::endl;
  std::cout << std::endl;

  // 3. Test [f]decreaseGrade
  std::cout << BLU << "[ TEST ] [f]decreaseGrade ]" << EOC << std::endl;
  std::cout << RED << "Before: " << EOC << b1 << std::endl;
  try
  {
    b1.decreaseGrade();
    std::cout << GRE << "Success to [f]decreaseGrade" << EOC << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << RED << "After: " << EOC << b1 << std::endl;
  std::cout << std::endl;

  // 4. Test [f]increaseGrade
  std::cout << BLU << "[ TEST] [f]increaseGrade] " << EOC << std::endl;
  std::cout << RED << "Before: " << EOC << b4 << std::endl;
  try
  {
    b4.increaseGrade();
    std::cout << GRE << "Success to [f]increaseGrade" << EOC << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << RED << "After: " << EOC << b4 << std::endl;
  std::cout << std::endl;

  return 0;
}
