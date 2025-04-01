/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:00:51 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:00:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* [ OCCF ]: 5ea */
// 1. Default constructor: Initialize member variables, when it's called.
ScalarConverter::ScalarConverter() : mError(false), mValue(0.0), mInput("") {}

// 2. Destructor
ScalarConverter::~ScalarConverter() {}

// 3. Copy constructor: Initialize member variables, when it's called.
ScalarConverter::ScalarConverter(const ScalarConverter& c) : mError(false), mValue(c.getValue()), mInput(c.getInput()) {}

// 4. Overloaded assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& c)
{
    if (this != &c)
    {
        mError = c.getError();
        *(const_cast<std::string*>(&mInput)) = c.getInput();
        *(const_cast<double*>(&mValue)) = c.getValue();
    }
    return (*this);
}

// 5. Parmeterized constructor
ScalarConverter::ScalarConverter(const std::string& input) : mError(false), mValue(0.0), mInput(input)
{
    try
    {
        // Test
        // std::cout << mError << std::endl;
        // std::cout << mValue << std::endl;
        // std::cout << mInput << std::endl;
        char *ptr = NULL;
        *(const_cast<double*>(&mValue)) = std::strtod(mInput.c_str(), &ptr);
        if (mValue == 0.0 && (mInput[0] != '-' && mInput[0] != '+' && !std::isdigit(mInput[0])))
        {
            throw std::bad_alloc();
        }
        if (*ptr && std::strcmp(ptr, "f"))
        {
            throw std::bad_alloc();
        }
    }
    catch (std::exception&)
    {
        mError = true;
    }
}

// ---------------------------------------------------------------------- //

/* [ Methods ] Getter: 3ea */
bool ScalarConverter::getError() const
{
    return (mError);
}

const double& ScalarConverter::getValue() const
{
    return (mValue);
}

const std::string& ScalarConverter::getInput() const
{
    return (mInput);
}

// ---------------------------------------------------------------------- //

/* [ Methods ] ScalarConverter: 4ea */
char ScalarConverter::toChar() const
{
    return (static_cast<char>(mValue));
}
  
int ScalarConverter::toInt() const
{
    return (static_cast<int>(mValue));
}

float ScalarConverter::toFloat() const
{
    return (static_cast<float>(mValue));
}

double ScalarConverter::toDouble() const
{
    return (static_cast<double>(mValue));
}

// ---------------------------------------------------------------------- //

/* [ Print ]: 5ea */
/*
    [ Role ]
    Param(c)값을 받아서 그 값이 NaN(Not-a-Number) || Infinity(무한대)인지를 검사하는 역할

    [ C++11 ]
    return (std::isnan(c.getValue()) || std::isinf(c.getValue()));

    [ Detail ]
    FP_ZERO: value==0
    FP_NORMAL: Normal value
    FP_INFINITE: infinity case
    FP_NAN: Not a number case
*/
bool isInvalidValue(const ScalarConverter& c)
{
    // FP_NAN과 FP_INFINITE를 사용하여 NaN 또는 Infinity를 검사
    int classification = std::fpclassify(c.getValue());
    return (classification == FP_NAN || classification == FP_INFINITE);
}

/*  [F]
    [ Role ]
     char형식으로 변환하여 출력

    [ Logic ]
    1. 변환할 수 없는 경우
        "impossible"

    2. 출력할 수 없는 경우
        "Non displayable"
*/
static void printAsChar(std::ostream& o, const ScalarConverter& c)
{
    o << "char: ";
    if (isInvalidValue(c))
        o << "impossible" << std::endl;
    else
    {
        char ch = c.toChar();
        if (std::isprint(ch))
            o << "'" << ch << "'" << std::endl;
        else
            o << "Non displayable" << std::endl;
    }
}

static void printAsInt(std::ostream& o, const ScalarConverter& c)
{
    o << "int: ";
    if (isInvalidValue(c))
        o << "impossible" << std::endl;
    else
        o << c.toInt() << std::endl;
}

/*
    [ Detail ]
    1. std::showpos         // 출력 시 양수 앞에 + 기호를 표시
    2. std::fixed           // 고정 소수점 형식으로 출력 (ex: 3.14159e+00)
    3. std::setprecision(7) // 소수점 이하 자릿수 설정 (ex: 7자리까지 출력)
*/
static void printAsFloatAndDouble(std::ostream& o, const ScalarConverter& c)
{
    // Error check
    if (isInvalidValue(c))
    {
        o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
        o << "double: " << std::showpos << c.toDouble() << std::endl;
        return ;
    }

    // Float
    if (c.toFloat() == static_cast<int64_t>(c.toFloat()))
        o << "float: " << c.toFloat() << ".0f" << std::endl;
    else
        o << "float: " << std::fixed << std::setprecision(7) << c.toFloat() << "f" << std::endl;

    // Double
    if (c.toDouble() == static_cast<int64_t>(c.toDouble()))
        o << "double: " << c.toDouble() << ".0" << std::endl;
    else
        o << "double: " << std::fixed << std::setprecision(15) << c.toDouble() << std::endl;
}
  
std::ostream& operator<<(std::ostream& o, const ScalarConverter& c)
{
    if (c.getError())
    {
        o << RED << "Allocation failed" << EOC << std::endl;
        return (o);
    }

    printAsChar(o, c);
    printAsInt(o, c);
    printAsFloatAndDouble(o, c);

    return (o);
}
