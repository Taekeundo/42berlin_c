/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:44:11 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:44:21 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define R       "\033[1;31m"
#define G       "\033[1;32m"
#define Y       "\033[1;33m"
#define B       "\033[1;34m"
#define P       "\033[1;35m"
#define C       "\033[1;36m"
#define EOC     "\033[0;0m"

#include <iostream>
#include <string>

/*
    Animal class

    [ Background ]
    Virtual function allow to override member function in sub-class(= child).

    [ Example ]

          Animal        // Parent
        /        \
     Dog          Cat   // Child

    [ memo ]
    over-riding function
        condition (1) public scope.
        condition (2) define with 'virtual' in parent.
    
    Derived classes(Cat & Dog)
    don't need to define member variable one-more time.
    Just use parent's protected member varaible.

    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator

    [ Member function ]
    1. getType

    [ Over-riding function from parent class ]
    1. makeSound
*/
class   Animal
{
    protected:
        std::string type; // Inherited member variable

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &rhs);
        Animal& operator=(const Animal &rhs);

        std::string getType() const;

        virtual void makeSound() const;
};

#endif
