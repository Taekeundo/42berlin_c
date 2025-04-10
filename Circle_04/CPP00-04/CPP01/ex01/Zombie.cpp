/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:44:07 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 13:44:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(){}

// Set name to member(private)
void Zombie::setName(std::string name)
{
    this->m_name = name;
    std::cout << "\t" << m_name << ": created" << std::endl;
}

// Same with EX00 in CPP01
void Zombie::announce(void)
{
    std::cout << "\t" << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
    std::cout << "\t" << m_name << ": destroyed" << std::endl;
}
