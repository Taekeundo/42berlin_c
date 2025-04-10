/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:35:07 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:35:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
    [ Background ]
    rhs: right hand side
    = 복사 생성자와 복사 대입 연산자에서 복사할 객체다.

    [ Call order ]
    Fixed a;
        Default constructor called (a)
        a's value: 0 (initialize)

    Fixed b(a);
        Copy constructor called (b)
        getRawBits called -> cpy a's value to b's value.
        b's value: 0

    Fixed c;
        Default constructor called (c)
        c's value: 0 (initialize)
    
    c = b;
        Copy assignment operator called
        If this(= 'c') isn't same with rhs(= 'b'),
        cpy b's value to c's value.
        c's value: 0
    
    print value(= 0) to the terminal 3 times.
        getRawBits member function called
        0
    
    [ Caution ]
    Why should we need 'copy assignement operator (ex) '=' ?
    
    Usually in C, operator('=') works only when the type is same.
    Computer can't know which member from Fixed that we want to compare.
    For this sitation, we use the operator overloading.
*/
int main( void )
{
    
    Fixed a;    // Declare 'Fixed' class type
    Fixed b(a); // Copy 'a' to 'b'
    Fixed c;    // Declare 'Fixed' class type

    c = b;      // Assign 'b' to 'c' by using user defined operator.

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
