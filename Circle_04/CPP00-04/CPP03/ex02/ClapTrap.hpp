/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:05:15 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/23 10:05:16 by tkwak            ###   ########.fr       */
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

/*  [F]
    [ Background ]
    protected // Access specifiers
    It can only be accessed within the parent class,
    and the derived classes that inherit it.

    A child class can only inherit variables,
    that are in protected scope from the parent class.
*/
class ClapTrap
{
    protected:
        std::string     m_name;
        unsigned int    m_hit_points;
        unsigned int    m_energy_points;
        unsigned int    m_attack_damage;
        
    public:
        ClapTrap();                                 // Default constructor
        ~ClapTrap();                                // Destructor
        ClapTrap(const ClapTrap &rhs);              // Copy constructor
        ClapTrap(std::string name);                 // Constructor with name param

        ClapTrap& operator=(const ClapTrap &rhs);   // Assignment operator
        std::string getName(void) const;            // Get the m_name from m_variable.

        void printStatus() const;                   // Member function(1)
        void attack(const std::string& target);     // Member function(2)
        void takeDamage(unsigned int amount);       // Member function(3)
        void beRepaired(unsigned int amount);       // Member function(4)
};

#endif