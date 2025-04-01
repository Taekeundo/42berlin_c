/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
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
#include <cmath>      // fpclassify(FP_INFINITE, FP_NAN)
#include <limits>     // numeric_limits
#include <cstdlib>    // std::atoi, std::atof, std::strtod
#include <cctype>     // std::isdigit()
#include <exception>  // std::exception
#include <cfloat>     // FLT_MAX is defined here.
#include <iomanip>    // std::fixed, std::setprecision
#include <cstring>    // strcmp

/* CLASS */
class ScalarConverter
{
  private:
    bool mError;
    const double mValue;
    const std::string mInput;

  public:
    /* [ OCCF ]: 5ea */
    ScalarConverter();                                      // Default constructor
    ~ScalarConverter();                                     // Destructor
    ScalarConverter(const ScalarConverter& other);          // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& rhs); // Overloaded assignment operator
    ScalarConverter(const std::string& input);              // Parmeterized constructor

    /* [ Getter ]: 3ea */
    bool getError() const;
    const double& getValue() const;
    const std::string& getInput() const;

    /* [ ScalarConverter ]: 4ea */
    int toInt() const;
    char toChar() const;
    float toFloat() const;
    double toDouble() const;
};

std::ostream& operator<<(std::ostream& o, const ScalarConverter& c);

#endif
