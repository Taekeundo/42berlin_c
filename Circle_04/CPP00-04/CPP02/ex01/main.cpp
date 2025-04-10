/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:36:41 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:36:42 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  [F]
    [ Call order ]
    Fixed a;                -> Default constructor called
    Fixed const b(10);      -> Int constructor called
    Fixed const c(42.42f);  -> Float constructor called
    Fixed const d(b);       -> Copy constructor called
    a = Fixed(1234.4321f);  -> Float constructor called
                            -> Copy assignment operator called
                            -> Destructor called
    print "a,b,c,d".        -> a is 1234.43
                            -> b is 10
                            -> c is 42.4219
                            -> d is 10
    print "a,b,c,d".        -> a is 1234 as integer
                            -> b is 10 as integer
                            -> c is 42 as integer
                            -> d is 10 as integer
    Destructor called       -> Destructor called // d
                            -> Destructor called // c
                            -> Destructor called // b
                            -> Destructor called // a

    [ Logic ]
    1. a = Fixed( 1234.4321f )

        (int)m_fixed_point
        = roundf(1234.4321 * 256)
        = roundf(316014.618)
        = 316015

        operator<<(std::cout, a);
            out << m_fixed.toFloat();
                << 316015 >> 8
                   316015 / 256
                   1234.43359

        Default value set for precision printing out values to stdout (= 6)
        Only print out 6 digits. but if digits from float type longer the 6digits,
        print every meaningful digits.
        = 1234.43

    2. c = Fixed( 42.42f )

        m_fixed_point
        = roundf(42.42 * 256)
        = roundf(10859.52)
        = 10860

        operator<<(std::cout, c);
            out << m_fixed.toFloat();
                << 10860 >> 8
                   10860 / 256
                   42.421875

        Default value set for precision printing out values to stdout (= 6)
        Only print out 6 digits.
        = 42.4219
    
    [ Caution ]
    std::cout의 출력 자릿수는 기본 설정에 따라 소수점 이하 6자리까지 출력을 설정.
*/
int main( void ) 
{
    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}