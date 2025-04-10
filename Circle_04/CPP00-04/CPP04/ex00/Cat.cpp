/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:43:51 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:43:51 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
Cat::Cat(void)
{
    std::cout << Y << "[Cat]" << EOC << " Default constructor" << std::endl;
    this->type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << Y << "[Cat]" << EOC << " Destructor" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
    std::cout << Y << "[Cat]" << EOC << " Copy constructor" << std::endl;
    (*this) = rhs;
}

Cat& Cat::operator=(const Cat &rhs)
{
    std::cout << Y << "[Cat]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/*  [F]
    Over-riding function from parent class.
*/
void Cat::makeSound() const
{
    std::cout << Y << "[Cat]" << EOC \
        << " Meow! Meow! Meow!" << std::endl;
}
