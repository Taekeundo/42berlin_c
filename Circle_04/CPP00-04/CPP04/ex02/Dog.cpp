/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:43:54 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:43:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
Dog::Dog(void)
{
    std::cout << G << "[Dog]" << EOC << " Default constructor" << std::endl;
    this->type = "Dog";
    this->m_brain = new Brain();
}

Dog::~Dog(void)
{
    delete (this->m_brain);
    std::cout << G << "[Dog]" << EOC << " Destructor" << std::endl;
}

Dog::Dog(const Dog &rhs)
{
    std::cout << G << "[Dog]" << EOC << " Copy constructor" << std::endl;
    this->type = rhs.type;
    delete (this->m_brain);
    this->m_brain = new Brain(*rhs.m_brain);
    for (int i = 0; i < 100; i++)
        this->m_brain->setIdea(rhs.m_brain->getIdea(i), i);
}

Dog& Dog::operator=(const Dog &rhs)
{
    std::cout << G << "[Dog]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
        delete (this->m_brain);
        this->m_brain = new Brain(*rhs.m_brain);
        for (int i = 0; i < 100; i++)
            this->m_brain->setIdea(rhs.m_brain->getIdea(i), i);
    }
    return (*this);
}

/*  [F]
    Over-riding function from parent class.
*/
void Dog::makeSound() const
{
    std::cout << G << "[Dog]" << EOC \
        << " WAU! WAU! WAU!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->m_brain);
}
