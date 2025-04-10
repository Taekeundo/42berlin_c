/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:44:33 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:44:33 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/*
    'Dog' Derived class, inherits from 'Animal' class.

    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator

    [ Over-riding function from parent class ]
    1. makeSound

    [ Member function]
    1. getBrain
*/
class Dog : public Animal
{
    private:
        Brain* m_brain;

    public:
        Dog();
        ~Dog();
        Dog(const Dog &rhs);
        Dog& operator=(const Dog &rhs);

        void makeSound() const;
        Brain* getBrain(void) const;
};

#endif
