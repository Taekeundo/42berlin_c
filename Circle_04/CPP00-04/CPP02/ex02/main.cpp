/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:37:13 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:37:14 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  [F]
    [ Mendatory ]
    comparision operators (6ea) : >, <, >=, <=, ==, !=
    arithmetic operators (4ea)  : +, -, *, /
    incre, decre operators (4ea): ++, --, const++, const--
    Overloaded functions (4ea)  : min, const min, max, const max

    [ What I learned from CPP02 ]
    1. Member variablem, function // scope: private, public.
    2. Default constructor, copy constructor, destructor, =operator
    3. Fixed point // Integer zone, Decimal zone
    -------------------------- ex00, ex01 --------------------------
    4. Operator overloading // Comparison, Arithmetic, incre & decre
        연산자를 내 입맛대로 구현할 수 있다.
    5. static function // max & min

    [ Testing for b's value ]
    std::cout << "b: " << b << std::endl;   // "b: 10.1016"
        Fixed(5.05f) : 5.05 * 256 = 1292.8 -> roundf -> 1293
        Fixed(2)     : 2 * 256 = 512
        toFloat(1293) * toFloat(512)
        5.05078 * 2
        10.10156 -> 6digits -> roundf -> 10.1016
        std::cout << b.getRawBits() << std::endl; // "2586"
    
    [ Background ]
    std::cout
        For 'float' type: print meaningful digits.
        For 'int' type  : print 6 digits.
*/
int main( void ) {
    Fixed           a;
    Fixed const     b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;    // 0
    std::cout << ++a << std::endl;  // 0.00390625   1/256 (2^-8)
    std::cout << a << std::endl;    // 0.00390625   1/256 (2^-8)
    std::cout << a++ << std::endl;  // 0.00390625   1/256 (2^-8)
    std::cout << a << std::endl;    // 0.0078125    2/256 (2^-8)

    std::cout << b << std::endl;    // 10.1016
    
    std::cout << Fixed::max( a, b ) << std::endl;   // 10.1016 (b is greater)

    return 0;
}