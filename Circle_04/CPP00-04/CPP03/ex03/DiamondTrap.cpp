/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:20:11 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/24 14:20:12 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*  [F]
	Default constructor

    [ Role ]
    Initialize three private member variables, when it's called.
        hp: from FragTrap = 100
        ep: from ScavTrap = 50
        ad: from FragTrap = 30
    
    [ Difference between FragClap and DiamondTrap ]
    Just put "_clap_name" to the name.
*/
DiamondTrap::DiamondTrap(void) 
{
    ClapTrap::m_name += "_clap_name";
    std::cout << "DiamondTrap_Default constructor " << std::endl;
    this->m_name = "DiamondTrap_default constructor";
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 30;
}

/*  [F]
    Destructor

    [ Goal ]
    Print "Destructor" & "Name of current object" & newline.
*/
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap_Destructor " << B << this->m_name << EOC << std::endl;
}

/*  [F]
    Copy constructor

    [ Role ]
    Operator overloading (User defined)
    = Copy all data from "rhs object(param)" to "current object(this)"."
*/
DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap_copy constructor " << std::endl;
    (*this) = rhs;
}

/*  [F]
    [ Definition ]
    Constructor using name in param.

    [ Logic ]
    1. Print "Constructor" & "name of object from param".
    2. Save(assign) value for the member variable of object.
        = Initialize.
*/
DiamondTrap::DiamondTrap(std::string name)
{
    ClapTrap::m_name = name + "_clap_name";
    this->m_name = name;
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 30;
    std::cout << B << "DiamondTrap" << EOC << " Constructor " \
        << B << "[" << name << "]" << EOC << std::endl;
    this->printStatus();
}

/*  [F]
    Overloaded assignment operator
    
    [ Logic ]
    Check ClapTrap.cpp // Same logic.
*/
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs)
{
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        this->m_hit_points = rhs.m_hit_points;
        this->m_energy_points = rhs.m_energy_points;
        this->m_attack_damage = rhs.m_attack_damage;
        std::cout << "FragTrap_duplicate of " \
            << B << "[" << this->m_name << "]" \
            << EOC << " has been created" << std::endl;
    }
    return (*this);
}

/*  [F]
    [ Role ]
    Attack target object(param).

    [ Condition ]
    Must use attack from ScavTrap class.
*/
void DiamondTrap::attack(const std::string& targetObject)
{
    ScavTrap::attack(targetObject);
}

/*  [F]
    [ Goal ]
    To print out two names.
    1. DiamondTrap's m_name.
    2. ClapTrap's m_name.

    It's the function in child class.
    Only can be called in child class.
*/
void DiamondTrap::whoAmi(void) const
{
    std::cout << B << "[DiamondTrap::whoAmi] " << EOC \
        << std::endl << "DiamondTrap name : " << this->m_name \
        << std::endl << "ClapTrap name    : " << ClapTrap::m_name \
        << std:: endl;
}