/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:17:53 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 17:17:54 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*  [F]
	Default constructor

    [ Role ]
    Initialize three private member variables, when it's called.
*/
ScavTrap::ScavTrap(void)
{
    std::cout << "ScanTrap_Default constructor " << std::endl;
    this->m_name = "ScanTrap_default constructor";
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 20;
}

/*  [F]
    Destructor

    [ Goal ]
    Print "Destructor" & "Name of current object" & newline.
*/
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScanTrap_Destructor " << this->m_name << std::endl;
}

/*  [F]
    Copy constructor

    [ Role ]
    Operator overloading (User defined)
    = Copy all data from "rhs object(param)" to "current object(this)"."
*/
ScavTrap::ScavTrap(const ScavTrap &rhs)
{
    std::cout << "ScanTrap_Copy constructor called" << std::endl;
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
ScavTrap::ScavTrap(std::string name)
{
    std::cout << Y << "ScavTrap" << EOC << " Constructor " \
        << Y << "[" << name << "]" << EOC << std::endl;
    this->m_name = name;
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 20;
    this->printStatus();
}

/*  [F]
    Assignment operator (Overloaded)
    
    [ Logic ]
    Check ClapTrap.cpp // Same logic.
*/
ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        this->m_hit_points = rhs.m_hit_points;
        this->m_energy_points = rhs.m_energy_points;
        this->m_attack_damage = rhs.m_attack_damage;
        std::cout << "ScanTrap_duplicate of " \
            << Y << "[" << this->m_name << "]" \
            << EOC << " has been created" << std::endl;
    }
    return (*this);
}

/*  [F]
    [ Role ]
    Attack target object(param).

    [ Reference ]
    Check (ClapTrap.cpp) // same logic

    [ Difference with attack in ClapTrap.hpp ]
    When attacking -> print out points of damage additionally.
*/
void ScavTrap::attack(const std::string& targetObject)
{
    if (this->m_hit_points < 1)
    {
        std::cout << "ScavTrap " << this->m_name \
            << " can't attack (Reason: Hit points < 1)" << std::endl;
        return ;
    }
    if (this->m_energy_points < 1)
    {
        std::cout << "ScavTrap " << this->m_name \
            << " can't attack (Reason: Energy points < 1)" << std::endl;
        return ;
    }
    this->m_energy_points--;
    std::cout << Y << "[ScavTrap::attack] " << EOC \
        << this->m_name << R \
        << " attacks " << EOC << targetObject \
        << ", causing " << R << this->m_attack_damage \
        << EOC << " points of damgage!" \
        << Y << " (energy point -1)" << EOC \
        << std::endl;
    this->printStatus();
}

/*  [F]
    [ Goal ]
    To print out the certain message for mandatory part.

    It's the function in child class.
*/
void ScavTrap::guardGate(void) const
{
    std::cout << Y << "[ScavTrap::guardGate] " << EOC \
        << this->m_name \
        << " is in gate keeper mode." << std::endl;
}