/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:08:44 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 12:08:45 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define R       "\033[1;31m"
#define G       "\033[1;32m"
#define Y       "\033[1;33m"
#define EOC     "\033[0;0m"

class ClapTrap
{
    private:
        std::string m_name;
        unsigned int m_hit_points;
        unsigned int m_energy_points;
        unsigned int m_attack_damage;
        
    public:
        ClapTrap(void);                                 // Default constructor
        ~ClapTrap(void);                                // Destructor
        ClapTrap(const ClapTrap &rhs);                  // Copy constructor
        ClapTrap(std::string name);                     // Constructor with name param

        ClapTrap& operator=(const ClapTrap &rhs);       // Assignment operator
        std::string getName(void) const;                // Get the m_name from the member variable.

        void printStatus() const;                       // Member function(1)
        void attack(const std::string& target);         // Member function(2)
        void takeDamage(unsigned int amount);           // Member function(3)
        void beRepaired(unsigned int amount);           // Member function(4)
};

#endif