/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:17:57 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 17:18:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*  [F]
    Class 'ScavTrap' inherited from 'ClapTrap'.

    [ Difference between ex02 ]
    inheriate "virtual" instance.
*/
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();                               // Default constructor
        ~ScavTrap();                              // Destructor
        ScavTrap(const ScavTrap &rhs);            // Copy constructor
        ScavTrap(std::string name);               // Constructor with name param

        ScavTrap& operator=(const ScavTrap &rhs); // Assignment operator

        void attack(const std::string& target);   // Over-riding.
        void guardGate(void) const;               // Child class function.
};

#endif