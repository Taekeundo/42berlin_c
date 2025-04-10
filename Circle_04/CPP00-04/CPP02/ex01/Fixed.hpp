/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:36:34 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:36:35 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

/*  [F]
    [ Definition ]
    Class stand for the fixed point.

    [ Fixed point: 고정소수점 ]
    2진수로 변환하는 수를 지정한 소수점 위치를 기준으로 정수와 소수를 나누어 그대로 넣는것.
    정수의 경우 m_bits만큼 좌측으로 이동시켜서 m_bits(비트)만큼의 소수점을 위한 자리수를 확보한다.

    32bits
    sign    +   00000000000000000000000   +   00000000
    -----------------------------------   +   ---------
                24ea                             8ea
            Integer part                     Decimal part

    [ Background ]
    1. integer to fixed point
    
        bit shift
        num << m_bits   // 정수 num을 소수점 m_bit만큼 왼쪽으로 옮겨서 저장.
        num * 2^m_bits  // m_bit만큼 비트를 옮겼다는건 정수가 2^_bits만큼 커졌다는 의미.

        !!Caution!!
        float, double type can't use bit shift(<<).
    
    2. float to fixed point

        ex) float f_val = 7.625
            
            convert to binary
                1. integer part: 7 (4 + 2 + 1)
                    = 111
                
                2. decimal part: 0.625
                    0.625 * 2 = 1.25    // 1
                    0.25  * 2 = 0.5     // 0
                    0.5   * 2 = 1       // 1
                    = 101
                
                = 111.101
                = 1.11101 * 2^2         // IEEE 754 표현

                sign    : 1
                exponent: 10000001
                fraction: 11101 + 000000000000000000

            convert to fixed point
                int fixed_point_value = (int)round(f_val * (1<<8));
                = (int)roundf(7.625 * 256)
                = (int)roundf(1952)
                = (int)1952 // decimal -> binary.
    
                    1952 / 2 = 976...0
                    976  / 2 = 488...0
                    488  / 2 = 244...0
                    244  / 2 = 122...0
                    122  / 2 = 61 ...0
                    61   / 2 = 30 ...1
                    30   / 2 = 15 ...0
                    15   / 2 = 7  ...1
                    7    / 2 = 3  ...1
                    3    / 2 = 1  ...1
                    1    / 2 = 0  ...1
                
                위의 과정을 역순으로 나머지를 읽어 이진수를 얻는다.
                = 11110100000 (11digits)
                = 00000 + 11110100000 (16digits)

    [ Memo ]
    1. static for "m_frac_bits"
        1. Share same variable with each other
            Every 'Fixed' object share the same variable (= 'm_frac_bits')
            = Don't need to define everytime -> Efficient memory management.
            (ex) Fixed a; Fixed b; -> a.m_frac_bits: 8 & b.m_frac_bits: 8.

        2. Maintanence & consistency (일관성 -> good variable control)
        When need to change code, fix one time, not change every time.

*/
class Fixed
{
    private:
        int m_fixed_point;                      // number of integer places.
        static const int m_frac_bits = 8;       // number of decimal places. 0000 0000
        
    public:
        /* Ex00 member functions */
        Fixed();                                // Default constructor
        ~Fixed();                               // Destructor
        Fixed(const Fixed &rhs);                // Copy constructor
        Fixed& operator=(const Fixed &rhs);     // Copy assignment operator

        /* Int & Float constructor */
        Fixed(const int value);                 // int i = 5        -> m_fixed_point: 1280
        Fixed(const float value);               // float f = 1.6f   -> m_fixed_point: 410

        /* Member functions */
        int getRawBits( void ) const;           // Get bits from current object.
        void setRawBits( int const raw );       // Set raw to the current object.
        float toFloat( void ) const;            // Convert [m_fixed_point] to float type.
        int toInt( void ) const;                // Convert [m_fixed_point] to int type.
};

/*  [F]
    An overload of the insertion («) operator
    inserts a floating-point representation of the fixed-point number
    into the output stream object passed as parameter.

    !!! Caution !!!
    std::cout << a
    ==> operator<<(std::cout, a); (same meaning)
*/
std::ostream& operator<<(std::ostream& out, const Fixed& m_fixed);

#endif