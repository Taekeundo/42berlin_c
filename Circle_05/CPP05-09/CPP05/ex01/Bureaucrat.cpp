/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:37:54 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 10:37:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* OCCF */
/* 1. Default constructor
    = Don't need to declare 1,2 -> cause it doesn't have any logic.
    = 아무 동작을 하지 않기 때문에 굳이 cpp파일에 선언하지 않고 헤더파일에만 선언해도 된다.
  
    굳이 기본값(Default, 150)을 넣어주는 이유
    = 안정성: 객체가 생성될 때 예상치 못한 값이 들어가는 것을 방지.
*/
Bureaucrat::Bureaucrat() : mName("Default"), mGrade(150) {}

// 2. Destructor
Bureaucrat::~Bureaucrat() {}

/* 3. Copy constructor
    = 대상의 멤버변수를 현재 오브젝트로 복사한다.
    = 점수가 주어진 instruction(H:1, L:150)범위에 있는지 체크한다.
*/
Bureaucrat::Bureaucrat(const Bureaucrat& other) : mName(other.getName()), mGrade(other.getGrade())
{
  if (mGrade < HIGHESTGRADE)
    throw GradeTooHighException();
  if (mGrade > LOWESTGRADE)
    throw GradeTooLowException();
}

/* 4. Overloaded assignment operator
    [ WHY ]
    "const_cast"
    = const타입의 수정 될 수 없는 변수를 수정해야만 할 때 강제로 사용하는 방식이다.
      mName은 클래스에서 const로 선언되어있고, mGrade는 아니다.

    [ 질문 ]
    함수 선언 시 mName을 초기화 해주면 되는거 아닌가?
    = if (this != &rhs)를 통해 자기 복제가 아닌지 확인 해야하는 과정이 필요하기에
      함수 선언시 초기화 하지 않는다.
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
  if (this != &rhs)
  {
    if (rhs.getGrade() < HIGHESTGRADE)
      throw GradeTooHighException();
    if (rhs.getGrade() > LOWESTGRADE)
      throw GradeTooLowException();
    const_cast<std::string&>(mName) = rhs.getName();
    mGrade = rhs.getGrade();
  }
  return (*this);
}

// 5. Parameterized constructor
// 전달받은 파라메터 (이름, 점수)를 확인하고
// 점수가 주어진 instruction(H:1, L:150)범위에 있는지 체크한다.
Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : mName(name), mGrade(grade)
{
  if (grade < HIGHESTGRADE)
    throw GradeTooHighException();
  if (grade > LOWESTGRADE)
    throw GradeTooLowException();
}

// ---------------------------------------------------------------------- //

/* Methods */
// Increase, decrease grade
// &를 사용해서 직접 mGrade의 값을 변경시킨다.
int& Bureaucrat::increaseGrade()
{
  if (mGrade <= HIGHESTGRADE)
    throw GradeTooHighException();
  --mGrade;
  return (mGrade);
}

int& Bureaucrat::decreaseGrade()
{
  if (mGrade >= LOWESTGRADE)
    throw GradeTooLowException();
  ++mGrade;
  return (mGrade);
}

/*
  [ Goal ]
  Bureaucrat 오브젝트가 Form 오브젝트에 서명 할 수 있는지를 확인하고
  서명이 가능할 경우 서명을, 불가능할 경우 예외 처리를 하는 함수.
*/
void Bureaucrat::signForm(Form& form) const
{
  try
  {
    form.beSigned(*this);
    std::cout << GRE << "= <" << mName << "> signs <"
              << form.getName() << ">" << EOC << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "<" << mName << "> " << RED << "could not" << EOC
              << " sign <" << form.getName() << "> because "
              << RED << "<" << e.what() << ">" << EOC << std::endl;
  }
}

// ---------------------------------------------------------------------- //

/* Exception */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Bureaucrat Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Bureaucrat Grade Too Low");
}

// ---------------------------------------------------------------------- //

/* Overloading operator '<<'
  [ Background ]
  1. Overloading
  = 기존 연산자(+, -, =, <<, >>, ..)를 사용자 정의 타입(클래스)에서 사용할 수 있도록 하는 기능.

  [ Param ]
  Param(1): output stream       To the terminal     std::cout
  Param(2): class Bureaucart&   Reference           Target for getting the information(name, grade).

  [ Role ]
  Print out target class's name and grade, following pdf's format.
  ex) <name>, bureaucrat grade <grade>.
*/
std::ostream& operator<<(std::ostream& o, const Bureaucrat& target)
{
  return (o << "<" << target.getName()
          << ">, bureaucrat grade <"
          << target.getGrade() << ">.");
}
