/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:00:51 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:00:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* [ OCCF ]: 4ea */
// 1. Default constructor
Converter::Converter() {}

// 2. Destructor
Converter::~Converter() {}

// 3. Copy constructor
Converter::Converter(const Converter& other)
{
    (*this) = other;
}

// 4. Overloaded assignment operator
Converter &Converter::operator=(const Converter& rhs)
{
    (void) rhs;
    return (*this);
}

// ---------------------------------------------------------------------- //

/* [ Methods ] print: 5ea */
/*  [F]
    [ Role ]
    int 타입으로 들어온 값을 char, float, double 타입으로 변환 후 출력한다.

    [ Background ]
    1. char type: 1bytes -> 8btis.
        = 0 0 0 0 0 0 0 0
        = 2*2*2*2*2*2*2*2
        = 2^8
        = 256 cases
        = Range: -128 ~ 127
        
        * ASCII: 128개로 제한한다. (0 ~ 127)
    
    2. 삼항 연산자 (? :)
        condition ? value_if_true : value_if_false;

    3. std::floor(f)
        소수점 이하를 버린 값을 반환.
        정수의 경우 버릴 소수점이 없기에 원래 값을 반환.
        if (f == std::floor(f))
        -> true
        -> 소수 버린값과 원래 값이 같다는걸 의미.
        -> 원래부터 f는 정수였다는걸 의미.

    [ Logic ]
    (1) static_cast // 강제 형변환
    
        1. char
            ASCII범위 내에서만 출력 가능.
            ASCII코드에 해당하는 0 ~ 127 범위롤 초과 할 경우 에러처리
            = "Impossible" || "Non displayable"로 처리.
            
            int: 4bytes, char: 1byte // 저장할 수 있는 크기를 초과한 값은 짤린다.
            ex) int i = 65 -> converting to char -> 'A'
                int i = 300 -> converting to char -> '44'
                    = 0b00101100 만 남고 나머지 부분이 짤려서 '44'가 된다.
        2. int: 그대로 출력
        3. float: float는 int보다 더 정밀해서 손실 없음.
        4. double: double은 float, int보다 더 정밀해서 손실 없음.

    [ Difference ]
    "Impossible"        // Out of ASCII range (0 - 127)
    "Non displayable"   // In ASCII range but can't be printable
                           ex) \n, \t, \b, ...

    i = 65      'A'     // 'A'
    i = 10      '\n'    // "Not displayable"
    i = 200     X       // "Impossible" (Out of ASCII range)
    i = -5      X       // "Impossible" (Out of ASCII range)
*/
void Converter::printInt(int i)
{
    char c = static_cast<char>(i);      // Convert (int) to (char)
    float f = static_cast<float>(i);    // Convert (int) to (float)
    double d = static_cast<double>(i);  // Convert (int) to (double)

    // 1. Check if (c) can be represented as a printable
    std::cout << "char: ";
    if (c < 0 || c > 127)
    {
        std::cout << "impossible";      // Out of ASCII range
    }
    else if (!std::isprint(c))
    {
        std::cout << "Non displayable"; // Non-printable ASCII char
    }
    else
    {
        std::cout << "'" << c << "'";   // Printable char
    }
    std::cout << std::endl;

    // 2. Print integer value directly. (정수 값 변경할 필요 없이 그대로 출력)
    std::cout << "int: " << i << std::endl;

    /* 3. Print float value with formatting. (실수 값 출력 및 형식 지정)
        (if) whole number (정수)
            = Append "0.f"
            = ex(1) 42    -> 42.0f로 표기해서 정확하기 float타입인걸 나타내준다.
        (else) Floating point number (소수)
            = just add "f". (소수점 있다면)
            = ex(2) 3.14  -> 3.14f로 그대로 표기해준다.
    */
    std::cout << "float: " << f;
    if (f == std::floor(f))
    {
        std::cout << ".0f";
    }
    else
    {
        std::cout << "f";
    }
    std::cout << std::endl;

    // 4. Same logic with 'float'
    std::cout << "double: " << d;
    if (d == std::floor(d))
    {
        std::cout << ".0";
    }
    else
    {
        std::cout << "";
    }
    std::cout << std::endl;
}

/*  [F]
    [ Role ]
    (char) 타입으로 들어온 값을 (int, float, double) 타입으로 변환 후 출력한다.

    [ Logic ]
    Similar with the [f]printInt
*/
void Converter::printChar(char c)
{
    int i = static_cast<int>(c);        // Convert (char) to (int)
    float f = static_cast<float>(c);    // Convert (char) to (float)
    double d = static_cast<double>(c);  // Convert (char) to (double)

    // 1. Check if (c) can be represented as a printable (char)
    std::cout << "char: ";
    if (c < 0 || c > 127)
    {
        std::cout << "impossible";      // Out of ASCII range
    }
    else if (!std::isprint(c))
    {
        std::cout << "Non displayable"; // Non-printable ASCII char
    }
    else
    {
        std::cout << "'" << c << "'";   // Printable char
    }
    std::cout << std::endl;

    // 2. Print (int) type value
    std::cout << "int: " << i << std::endl;

    // 3. Print (float) type value with formatting
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;

    // 4. Print (double) type value with formatting
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

/*  [F]
    [ Role ]
    (float) 타입으로 들어온 값을 (char, int, double) 타입으로 변환 후 출력한다.

    [ Background ]
    std::numberic_limits<int>::min()
    std::numberic_limits<int>::max()
    = int타입이 가질 수 있는 최소값과 최대값을 알려주는 C++표준 라이브러리 기능.

*/
void Converter::printFloat(float f)
{
    char c = static_cast<char>(f);      // Convert (float) to (char)
    int i = static_cast<int>(f);        // Convert (float) to (int)
    double d = static_cast<double>(f);  // Convert (float) to (double)

    // 1. Check if (c) can be represented as a printable (char)
    std::cout << "char: ";
    if (c < 0 || c > 127)
    {
        std::cout << "impossible";      // Out of ASCII range
    }
    else if (!std::isprint(c))
    {
        std::cout << "Non displayable"; // Non-printable ASCII char
    }
    else
    {
        std::cout << "'" << c << "'";   // Printable char
    }
    std::cout << std::endl;    

    /* 2. Check if the (float) type value can fit into an (int) and print it.
        std::numberic_limits<int>::min
        = -2,147,483,648

        std::numberic_limits<int>::max
        = +2,147,483,647

        Out of the <int> range -> "impossible"
    */
    if (std::numeric_limits<int>::min() <= i && i <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // 3. Check if the (float) type value can be represented as a valid (float) and print it.
    if (std::numeric_limits<float>::min() <= f && f <= std::numeric_limits<float>::max())
        std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    // 4. Check if the (float) type value can be represented as a valid (double) and print it.
    if (std::numeric_limits<double>::min() <= d && d <= std::numeric_limits<double>::max())
        std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

/*  [F]
    [ Role ]
    (double) 타입으로 들어온 값을 (char, int, float) 타입으로 변환 후 출력한다.
*/
void Converter::printDouble(double d)
{
    char c = static_cast<char>(d);      // Convert (double) to (char)
    int i = static_cast<int>(d);        // Convert (double) to (int)
    float f = static_cast<float>(d);    // Convert (double) to (float)

    // 1. Check if (c) can be represented as a printable (char)
    std::cout << "char: ";
    if (c < 0 || c > 127)
    {
        std::cout << "impossible";      // Out of ASCII range
    }
    else if (!std::isprint(c))
    {
        std::cout << "Non displayable"; // Non-printable ASCII char
    }
    else
    {
        std::cout << "'" << c << "'";   // Printable char
    }
    std::cout << std::endl;    

    // 2. Check if the (double) type value can fit into an (int) and print it.
    if (std::numeric_limits<int>::min() <= i && i <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // 3. Check if the (double) type value can be represented as a valid (float) and print it. 
    if (std::numeric_limits<float>::min() <= f && f <= std::numeric_limits<float>::max())
        std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    // 4. Check if the (double) type value can be represented as a valid (double) and print it.
    if (std::numeric_limits<double>::min() <= d && d <= std::numeric_limits<double>::max())
        std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

/*  [F]
    [ Role ]
    Param(1) val값이 특정한(float, double)값 (= nanf, -inff, +inff, ...)일 경우
    그에 맞게 형식을 조정해서 출력한다.

    [ Background ]
    (1) Special cases
        [ double type only ]
        nan      |   Not a number
                 |   ex) 0.0 / 0.0, std::sqrt(-1.0), inf - inf, nan + 1.0)
        inf      |   Infinity
                 |   ex) 1.0 / 0.0
        -inf     |   Infinity // Negative version of the 'inf'
        ------------------------------------------------------------------
        [ float type only ]
        nanf     |   nan + 'f'   // float version of the 'nan'
        inff     |   Inf + 'f'   // float version of the 'inf'
        -inff    |   Inf + 'f'   // Negative version of the 'inff'
    
    (2) std::atof
        Convert (string) to (double). // always double.
*/
void Converter::printNanInfValues(const std::string &val)
{
    // (char, int)type doesn't have any (nan, inf) cases.
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    // Handling 'float' type
    std::cout << "float: ";
    if (val == "nanf" || val == "+inff" || val == "-inff")
        std::cout << val << std::endl;
    else
        std::cout << val << "f" << std::endl;

    // Handling 'double' type
    // else if, else는 같은 동작을 하지만 코드의 가독성을 높이기 위해 일부로 나눴다.
    std::cout << "double: ";
    if (val == "nanf")
        std::cout << "nan" << std::endl;
    else if (val == "+inf" || val == "-inf")
        std::cout << val << std::endl;
    else
        std::cout << val << std::endl;
}

// ---------------------------------------------------------------------- //

/* [ Methods ] convert: 1ea */
/*
    [ Role ]
    Param(1): val을 여러 데이터 타입으로 변환하고 그 값을 터미널에 출력한다.

    [ Logic ]
    1. Check the size
        a. size == 0    // Empty case
            Handling size exception
        b. size == 1    // Single character
            Check [digit or char]
            O: [f]printInt();
            X: [f]printChar();
    2. Check Nan || Inf
    3. Convert various type to print
        int -> float -> double
    4. Handle exceptional case

    [ ETC ]
    In C++98 version: atod X, use [f]std::strtod
*/
void Converter::convert(const std::string &val)
{
    if (val.size() == 0)
        throw Converter::InputSizeNull();
    else if (val.size() == 1)
    {
        if (std::isdigit(val[0]))
        {
            int d = std::atoi(val.c_str());
            Converter::printInt(d);
        }
        else
            Converter::printChar(val[0]);
    }
    else if (isNanInf(val))
        Converter::printNanInfValues(val);
    else
    {
        if (isInt(val))
        {
            int d = std::atoi(val.c_str());
            Converter::printInt(d);
        }
        else if (isFloat(val))
        {
            float f = std::atof(val.c_str());
            Converter::printFloat(f);
        }
        else if (isDouble(val))
        {
            char *endPtr;   // 문자열에서 숫자 변환이 끝난 지점을 추적
            double convertedDouble = std::strtod(val.c_str(), &endPtr);
            // strtod가 성공적으로 실행되었다면 endPtr은 '\0'을 가리킨다.
            if (*endPtr == '\0')
                Converter::printDouble(convertedDouble);
            else
            {
                throw Converter::InvalidInputException();
            }
        }
        else
            throw Converter::InvalidInputException();
    }
}

// ---------------------------------------------------------------------- //

/* [ Exception ]: 2ea */
const char* Converter::InvalidInputException::what(void) const throw()
{
    return (RED "Error: Invalid input" EOC);
}

const char* Converter::InputSizeNull::what(void) const throw()
{
    return (RED "Error: Input size is null" EOC);
}

// ---------------------------------------------------------------------- //

/* [Check data type]: 4ea */
// [F]
bool isDigitChar(char c)
{
    if ('0' <= c && c <= '9')
        return (1); // true
    if (c == '+' || c == '-' || c == 'E' || c == 'e')
        return (1); // true
    // e || E == 3.14e2, 1.23E4 (과학적 표기법)에서 사용하기에 넣어줘야함.
    return (0);
}

// [F]
bool isInt(const std::string& val)
{
    unsigned long startIndex = 0;

    if (val[0] == '+' || val[0] == '-')
        startIndex = 1; // true
    for (unsigned long i = startIndex; i < val.length(); i++)
    {
        if (!std::isdigit(val[i])) // 숫자가 아닐 경우
            return (0);            // false
    }
    return (1); // 모든 문자가 숫자라면 true
}

/* [F]
    [ Role ]
    Param(1) val이 유효한 float타입의 숫자 형식인지 확인하는 함수.

    [ Case ]
    state == 0      초기상태 (숫자 || 부호가 올 수 있음)
    state == 1      소수점 앞에 숫자가 올 수 있음
    state == 2      소수점 뒤에 숫자 또는 'f'가 올 수 있음
    state == 3      소수점 뒤에 숫자가 올 수 있음.
    state == 4      유효한 float형식일 경우.

    [ Logic ]
    1. + 또는 -로 시작할 경우 다음 문자로 건너 뛰기.
    2. 숫자 처리 -> state: 1 -> 소수점, 추가 숫자 받기
*/
bool isFloat(const std::string& val)
{
    int state = 0;
    unsigned long startIndex = (val[0] == '+' || val[0] == '-') ? 1 : 0;

    for (unsigned long i =  startIndex; i < val.length(); i++)
    {
        if (state == 0 && isDigitChar(val[i]))
            state = 1;
        else if (state == 0 && !isDigitChar(val[i]))
            return (0);
        else if (state == 1 && val[i] == '.')
            state = 2;
        else if (state == 1 && val[i] != '.' && !isDigitChar(val[i]))
            return (0);
        else if (state == 2 && isDigitChar(val[i]))
            state = 3;
        else if ((state == 2 || state == 3) && !isDigitChar(val[i]) && val[i] != 'f')
            return (0);
        else if (state == 3 && val[i] == 'f')
            state = 4;
    }
    return (state == 4);
}

// [F] similar with isFloat();
bool isDouble(const std::string& val)
{
    int d = 0;
    for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
    {
        if (d == 0 && isDigitChar(val[i]))
            d = 1;
        else if (d == 0 && !isDigitChar(val[i]))
               return (0);
        else if (d == 1 && val[i] == '.')
               d = 2;
        else if (d == 1 && val[i] != '.' && !isDigitChar(val[i]))
               return (0);
        else if (d == 2 && isDigitChar(val[i]))
              d = 3;
        else if ((d == 2 || d == 3) && !isDigitChar(val[i]))
            return (0);
    }
    return (d == 3);
}

// [F]
bool isNanInf(const std::string& val)
{
    return (val == "nan" || val == "+inf"
                        || val == "-inf" || val == "nanf"
                        || val == "+inff" || val == "-inff");
}
