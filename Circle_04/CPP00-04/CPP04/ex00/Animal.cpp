/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:43:46 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:43:48 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
Animal::Animal(void)
{
    std::cout << B << "[Animal]" << EOC << " Default constructor" << std::endl;
    this->type = "Animal";
}

Animal::~Animal(void)
{
    std::cout << B << "[Animal]" << EOC << " Destructor" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
    std::cout << B << "[Animal]" << EOC << " Copy constructor" << std::endl;
    (*this) = rhs;
}

Animal& Animal::operator=(const Animal &rhs)
{
    std::cout << B << "[Animal]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/*  [F]
    Member function
*/
std::string Animal::getType() const
{
    return (this->type);
}

/*  [F]
    Over-riding function for child class
*/
void Animal::makeSound() const
{
    std::cout << B << "[Animal]" << EOC \
        << " Doesn't make sound " << std::endl;
}
