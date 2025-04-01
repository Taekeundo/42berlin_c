/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:00:54 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:00:54 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

/* MACRO */
// Bold color definitions using ANSI
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
#include <iostream>   // std::cout, std::cerr
#include <string>     // std::string
#include <cmath>      // floor, isnan(), isinf()
#include <limits>     // numeric_limits
#include <cstdlib>    // std::atoi, std::atof, std::strtod
#include <cctype>     // std::isdigit()
#include <exception>  // std::exception

/* CLASS */
class Converter
{
  private:

  public:
    /* [ OCCF ]: 4ea */
    Converter();                                // Default constructor
    ~Converter();                               // Destructor
    Converter(const Converter& other);          // Copy constructor
    Converter& operator=(const Converter& rhs); // Overloaded assignment operator

    /* [ Methods ] */
    // Print: 5ea
    /*  [ static method ]
        멤버 변수나 객체 상태에 비의존적인 메소드의 경우 static으로 선언하는게 좋다.
        -> static메소드의 경우 별도의 object생성없이 바로 호출이 가능하다.
        -> 객체의 상태나 데이터를 사용하지 않기에(의존X) 인스턴스를 만들 필요가 없다.
        -> 주로 print || convert 계열의 객체와 관계없이 특정 기능을 수행할 경우 static으로 선언한다.

        [ method를 사용하기 위해 object생성을 꼭 해야하는 경우 ]
        calss MyClass {
        public:
          int value;

          void setValue(int val)
            value = val;
        }
      
        int main() {
          MyClass obj;
          obj.setValue(10);
          std::cout << obj.value << std::endl;
        }
    
        = Member variable이 있기 때문에 static함수를 사용할수없다.
        = 모든 오브젝트마다 서로 다른 memever variable을 갖고 있을수 있기 때문에.
    */
    static void printInt(int i);
    static void printChar(char c);
    static void printFloat(float f);
    static void printDouble(double d);
    static void printNanInfValues(const std::string& val);

    // Convert: 1ea
    static void convert(const std::string& val);

    /* [ Exception ]: 2ea */
    class InvalidInputException : public std::exception
    {
      const char* what() const throw();
    };

    class InputSizeNull : public std::exception
    {
      const char* what() const throw();
    };
};

/* [Check data type]: 5ea */
bool isDigitChar(char c);
bool isInt(const std::string& val);
bool isFloat(const std::string& val);
bool isDouble(const std::string& val);
bool isNanInf(const std::string& val);

#endif
