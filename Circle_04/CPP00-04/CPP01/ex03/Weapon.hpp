/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:03:48 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:03:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>    // std::cout, std::endl
#include <string>       // std::string

/*  [F]
    Const variable & Reference -> must initialize immediately to be called.
*/
class   Weapon
{
    private:
        std::string m_type;

    public:
        Weapon(std::string type);           // Constructor.
        ~Weapon();                          // Destructor.
        const std::string   &getType();     // Get type(reference). // const
        void    setType(std::string type);  // Cpy current 'type' to 'm_type'.
};

#endif
