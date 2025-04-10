/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:37:06 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:37:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int m_fixed_point;                          // number of integer places.
        static const int m_frac_bits = 8;           // number of decimal places.
        
    public:
        /* Ex00 member functions */
        Fixed();                                    // Default constructor
        ~Fixed();                                   // Destructor
        Fixed(const Fixed &rhs);                    // Copy constructor
        Fixed& operator=(const Fixed &rhs);         // Copy assignment operator

        /* Ex01 member functions */
        Fixed(const int value);                     // Int constructor
        Fixed(const float value);                   // Float constructor
        int getRawBits( void ) const;               // Get bits from current object.
        void setRawBits( int const raw );           // Set raw to the current object.
        float toFloat( void ) const;                // Convert [m_fixed_point] to float type.
        int toInt( void ) const;                    // Convert [m_fixed_point] to int type.

        /* Comparision operators (6ea) */
        bool operator>(const Fixed &rhs) const;     // Greater          >
        bool operator<(const Fixed &rhs) const;     // less             <
        bool operator>=(const Fixed &rhs) const;    // Greater or same  >=
        bool operator<=(const Fixed &rhs) const;    // less or same     <=
        bool operator==(const Fixed &rhs) const;    // Same             ==
        bool operator!=(const Fixed &rhs) const;    // Not same         !=

        /* Arithmetic operators (4ea) */
        Fixed operator+(const Fixed &rhs) const;    // Plus             +
        Fixed operator-(const Fixed &rhs) const;    // Minus            -
        Fixed operator*(const Fixed &rhs) const;    // Multiply         *
        Fixed operator/(const Fixed &rhs) const;    // Divide           /
        
        /* Increment, decrement operators (4ea) */
        Fixed& operator++(void);                    // Pre-increment
        Fixed& operator--(void);                    // Pre-decrement
        const Fixed operator++(int);                // Post-increment   const
        const Fixed operator--(int);                // Post-decrement   const
        
        /* Overloaded functions (4ea) */
        static const Fixed& max(const Fixed& _fixed1, const Fixed& _fixed2);    // const max
        static const Fixed& min(const Fixed& _fixed1, const Fixed& _fixed2);    // const min
        static Fixed& max(Fixed& _fixed1, Fixed& _fixed2);                      // max
        static Fixed& min(Fixed& _fixed1, Fixed& _fixed2);                      // min
};

/*  [F] Same function with ex01
    An overload of the insertion («) operator
    inserts a floating-point representation of the fixed-point number
    into the output stream object passed as parameter.

    !!! Caution !!!
    std::cout << a
    ==> operator<<(std::cout, a); (same meaning)
*/
std::ostream& operator<<(std::ostream& out, const Fixed& _fixed);

#endif
