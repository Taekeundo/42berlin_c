/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:03:04 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:03:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

/*  [F]
    [ Difference from "HUMANB" ]
    member variable(m_weapon)'s type -> &(reference)
    
    Must initialize when constructor is called.

*/
class HumanA
{
    private:
        std::string m_name;
        Weapon &m_weapon;

    public:
        HumanA(std::string name, Weapon &weapon);
        void    setWeapon(Weapon weapon);
        void    attack();
        ~HumanA();
};

#endif
