/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:20:08 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/29 10:20:11 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator
*/
Brain::Brain(void)
{
    std::cout << P << "[Brain]" << EOC << " Default constructor" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << P << "[Brain]" << EOC << " Destructor" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
    std::cout << P << "[Brain]" << EOC << " Copy constructor" << std::endl;
    (*this) = rhs;
}

// Copy 'ideas'array [0 ~ 100].
Brain& Brain::operator=(const Brain &rhs)
{
    std::cout << P << "[Brain]" << EOC << " Assignment operator" << std::endl;
    if (this != &rhs)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

/*  [F]
    Member function
*/
std::string Brain::getIdea(int n) const
{
    if (n >= 0 && n <= 99)
        return (this->ideas[n]);
    else
        return ("Range must be over 0 under 100");
}

void Brain::setIdea(std::string new_idea, int n)
{
    if (n >= 0 && n <= 99)
        this->ideas[n] = new_idea;
    else
    {
        std::cout << P << "[Brain]" << EOC \
            << R << "Range must be over 0 under 100" \
            << EOC << std::endl;
    }
}
