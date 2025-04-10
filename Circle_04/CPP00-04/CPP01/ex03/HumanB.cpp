/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:03:10 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:03:12 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*  [F]
    m_name, m_weapon // Not '&' and 'const' then can intialize in scope.

    [ Another way to initialize ]
    member initialization list // more efficient and clear.

    HumanB::HumanB(std::string name) : m_name(name), m_weapon(nullptr)
    {
        std::cout << "HumanB(" << name << ") created with no weapon" << std::endl;
    }

*/
HumanB::HumanB(std::string name)
{
    this->m_name = name;
    this->m_weapon = NULL;
    std::cout << "HumanB(" << name << ") created with no weapon" << std::endl;
}

/*  [F]
    parameter type: &(reference)
    Don't need to copy again. -> memory efficient.
*/
void HumanB::setWeapon(Weapon &weapon)
{
    this->m_weapon = &weapon;
}

/*  [F]
*/
void HumanB::attack()
{
    std::cout << this->m_name << " attacks with their "
        << this->m_weapon->getType() << std::endl;
}

/*  [F]
*/
HumanB::~HumanB()
{
    std::cout << "HumanB(" << this->m_name << ") destroyed" << std::endl << std::endl;
}
