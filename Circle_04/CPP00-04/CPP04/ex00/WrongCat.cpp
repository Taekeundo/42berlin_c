/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:44:07 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:44:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
WrongCat::WrongCat(void)
{
    std::cout << Y << "[WrongCat]" << EOC << " Default constructor" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
    std::cout << Y << "[WrongCat]" << EOC << " Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    std::cout << Y << "[WrongCat]" << EOC << " Copy constructor" << std::endl;
    (*this) = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << Y << "[WrongCat]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/*  [F]
    Over-riding function from parent class.
*/
void WrongCat::makeSound() const
{
    std::cout << Y << "[WrongCat]" << EOC \
        << " Doesn't make sound " << std::endl;
}
