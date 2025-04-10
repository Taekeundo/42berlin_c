/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:54 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 11:18:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Basic: 2ea - Constructor & Destructor
Zombie::Zombie(std::string name)
{
    this->zombieName = name;
    std::cout << this->zombieName << ": created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->zombieName << ": destroyed" << std::endl;
}

// Methode
void Zombie::announce(void)
{
    std::cout << this->zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}