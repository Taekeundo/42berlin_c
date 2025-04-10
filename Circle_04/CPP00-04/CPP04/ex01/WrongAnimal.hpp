/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:44:40 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:44:41 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#define R       "\033[1;31m"
#define G       "\033[1;32m"
#define Y       "\033[1;33m"
#define B       "\033[1;34m"
#define EOC     "\033[0;0m"

#include <iostream>
#include <string>

/*
    WrongAnimal class, same as with Animal class.

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
class   WrongAnimal
{
    protected:
        std::string type; // Inherited memver variable

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &rhs);
        WrongAnimal& operator=(const WrongAnimal &rhs);

        std::string getType() const;
        void makeSound() const;
};

#endif
