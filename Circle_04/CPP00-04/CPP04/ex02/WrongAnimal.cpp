/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:44:02 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:44:03 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
WrongAnimal::WrongAnimal(void)
{
    std::cout << B << "[WrongAnimal]" << EOC << " Default constructor" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << B << "[WrongAnimal]" << EOC << " Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << B << "[WrongAnimal]" << EOC << " Copy constructor" << std::endl;
    (*this) = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << B << "[WrongAnimal]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/*  [F]
    Member function
*/
std::string WrongAnimal::getType() const
{
    return (this->type);
}

/*  [F]
    Over-riding function for child class
*/
void WrongAnimal::makeSound() const
{
    std::cout << B << "[WrongAnimal]" << EOC \
        << " Doesn't make sound " << std::endl;
}
