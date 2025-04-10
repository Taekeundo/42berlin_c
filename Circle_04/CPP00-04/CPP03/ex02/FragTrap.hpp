/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:18:27 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 17:18:28 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

/*  [F]
    Class 'ScavTrap' inherited from 'ClapTrap'.
*/
class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();                                 // Default constructor
        ~FragTrap();                                // Destructor
        FragTrap(const FragTrap &_FragTrap);        // Copy constructor
        FragTrap(std::string name);                 // Constructor with name param

        FragTrap& operator=(const FragTrap& rhs);   // Assignment operator

        void attack(const std::string& target);   // Over-riding.
        void highFivesGuys(void) const;             // Child class function
};

#endif