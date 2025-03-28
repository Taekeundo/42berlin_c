/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:48 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

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
#include <iostream>     // std::cout, std::cerr
#include <cstdlib>      // std::rand(), std::srand()
#include <ctime>        // std::time(0)
#include <exception>    // exception(try, catch, throw)
#include <new>          // std::bad_alloc

/* CLASS */
/*  [F]
    Abstract class, only for the inheritance.
    = It has only a public virtual destructor.
*/
class Base
{
    public:
        virtual ~Base();    // Destructor (Virtual)
};

/*  [F]
    Create three empty classes A, B and C that inherit from 'Base' class.
*/
class A : public Base {};
class B : public Base {};
class C : public Base {};

/*  [F]
    [ Role ]
    It instanciates A, B or C randomly and returns a Base pointer, which points to that instance.
*/
Base*   generate();

/*  [F]
    [ Difference, if the cast is not valid ]
    
    1. dynamic_cast with *(pointers)
        = It returns a null pointer

    2. dynamic_cast with &(references)
        = It throws an exception (std::bad_cast)

    [ Role ]
    *p
    It prints the actual type of the object, is pointed to by p: "A", "B" or "C".

    &p
    Same function with over [f]identify but using &(Reference) instead of using (pointer)
*/
void    identify(Base* p);
void    identify(Base& p);

#endif
