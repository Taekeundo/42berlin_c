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
void Converter::printInt(int i)
{
    char c = static_cast<char>(i);      // int to char
    float f = static_cast<float>(i);    // int to float
    double d = static_cast<double>(i);  // int to double
}

void Converter::printChar(char c)
{
    int i = static_cast<char>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
}

void Converter::printFloat(float f);
void Converter::printDouble(double d);
void Converter::printSpecial(const std::string& val);

// ---------------------------------------------------------------------- //

/* [ Methods ] convert: 1ea */
void Converter::convert(const std::string &val)
{}

// ---------------------------------------------------------------------- //

/* [ Exception ]: 1ea */
const char* Converter::InvalidInputException::what(void) const throw()
{
    return ("Invalid input");
}

// ---------------------------------------------------------------------- //

/* [Check data type]: 4ea */
bool isInt(std::string const &val)
{}

bool isFloat(std::string const &val)
{}

bool isDouble(std::string const &val)
{}

bool isSpecial(std::string const &val)
{
    return (val == "nan" || val == "nanf" || val == "-inff"
                        || val == "+inff" || val == "-inf"
                        || val == "+inf");
}
