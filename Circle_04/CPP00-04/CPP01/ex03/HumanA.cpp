/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:02:55 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:02:57 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*  [F]
    m_name's type isn't & or const.
    But just initialize by using "member initialization list" for the memory efficience.

    After calling constructor, HumanA has 'name' and 'weapon' at the same time.
*/
HumanA::HumanA(std::string name, Weapon &weapon):m_name(name), m_weapon(weapon)
{
    std::cout << "HumanA(" << name << ") created with ";
    std::cout << weapon.getType() << std::endl;
}

/*  [F]
*/
void    HumanA::setWeapon(Weapon weapon)
{
    this->m_weapon = weapon;
}

/*  [F]
*/
void    HumanA::attack()
{
    std::cout << this->m_name << " attacks with their "
        << this->m_weapon.getType() << std::endl;
}

/*  [F]
*/
HumanA::~HumanA()
{
    std::cout << "HumanA(" << this->m_name << ") destroyed" << std::endl << std::endl;
}