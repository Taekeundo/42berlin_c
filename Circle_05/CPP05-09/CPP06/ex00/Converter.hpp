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
#include <cstdlib>    // malloc, free, rand, exit
#include <cmath>      // floor
#include <limits>     // numeric_limits
#include <cstring>    // strlen
#include <cerrno>     // errno
#include <exception>  // std::exception

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
    static void printInt(int i);
    static void printChar(char c);
    static void printFloat(float f);
    static void printDouble(double d);
    static void printSpecial(const std::string& val);

    // Convert: 1ea
    static void convert(const std::string& val);

    /* [ Exception ]: 1ea */
    class InvalidInputException : public std::exception
    {
      const char* what() const throw();
    };
};

/* [Check data type]: 4ea */
bool isInt(const std::string& val);
bool isFloat(const std::string& val);
bool isDouble(const std::string& val);
bool isSpecial(const std::string& val);

#endif
