#ifndef ARRAY_HPP
#define ARRAY_HPP

/* MACRO */
// Bold color definitions using ANSI for printing in the terminal.
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
// Basic
#include <string>       // std::string
#include <iostream>     // std::cout
#include <cstdlib>      // ??
#include <exception>    // std::exception

/* Class */
/* [ Memo ]
    1. Why to use 'explicit'
        int a = 5;
        double b = a;
        = return the 'a' automatically with double type.

        public: 
            Myclass(int n)

        int main() {
            Myclass obj = 10;
        }   
        = 컴퓨터가 자동으로 "Myclass obj = 10;" 명제를 "Myclass(10)"로 인식한다.
        = 이럴때 explicit를 붙여주면 무조건 Myclass(10)로 작성되야만 컴퓨터가 인식한다.
*/
template <typename T>
class Array
{
    private:
        T*  array;
        int size;

    public:
        /* [ OCCF: Orthodox Canonical Class Form ] */
        // 1. Default constructor
        Array() : size(0), array(NULL) {}

        // 2. Destructor
        ~Array()
        {
            if (size)
            {
                delete[] array;
                array = NULL;
                size = 0;
            }
        }

        // 3. Parameterized constructor
        explicit Array(int n)
        {
            if (n <= 0)
            {
                size = 0;
                array = NULL;
            }
            else
            {
                size = n;
                array = new T[size];
            }
        }

        // 4. Copy constructor
        Array(Array const& other) : size(other.getSize()), array(NULL)
        {
            if (size)
                array = new T[size];
            for (int i = 0; i < size; ++i)
                array[i] = other[i];
        }

        // 5. Overloaded assignment operator
        Array& operator=(const Array& rhs)
        {
            if (this != &rhs)
            {
                if (size)
                {
                    delete[] array; // delete previous data.
                    array = NULL;
                    size = 0;
                }
                size = rhs.getSize();
                if (size)
                    array = new T[size];
                for (int i = 0; i < size; ++i)
                    array[i] = rhs[i];
            }
            return (*this);
        }

        // 6. Overloaded "[]" bracket operator
        T& operator[](int index)
        {
            if (index >= size || index < 0)
                throw OutOfRange();
            return array[index];
        }

        // 7. Overloaded const "[]" bracket operator
        const T& operator[](int index) const
        {
            if (index >= size || index < 0)
                throw OutOfRange();
            return array[index];
        }

        /* [ Methods ] */
        int getSize() const
        {
            return (size);
        }

        /* [ Exceptional case ] */
        class OutOfRange: public std::exception
		{
			public:
                const char* what() const throw()
                {
                    return ("Out of Range");
                }
		};
};

#endif
