/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:03:15 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:03:17 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

/*  [F]
    [ member variable ]
    No const and reference type.
*/
class HumanB
{
    private:
        std::string m_name;
        Weapon *m_weapon;

    public:
        HumanB(std::string name);           // Constructor
        void setWeapon(Weapon &weapon);
        void attack();
        ~HumanB();                          // Destructor
};

#endif
