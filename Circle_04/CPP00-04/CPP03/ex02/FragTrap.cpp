/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:18:23 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 17:18:24 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*  [F]
	Default constructor

    [ Role ]
    Initialize three private member variables, when it's called.
*/
FragTrap::FragTrap(void) 
{
    std::cout << "FragTrap_Default constructor " << std::endl;
    this->m_name = "FragTrap_default constructor";
    this->m_hit_points = 100;
    this->m_energy_points = 100;
    this->m_attack_damage = 30;
}

/*  [F]
    Destructor

    [ Goal ]
    Print "Destructor" & "Name of current object" & newline.
*/
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap_Destructor " << R << this->m_name << EOC << std::endl;
}

/*  [F]
    Copy constructor

    [ Role ]
    Operator overloading (User defined)
    = Copy all data from "rhs object(param)" to "current object(this)"."
*/
FragTrap::FragTrap(const FragTrap &rhs)
{
    std::cout << "FragTrap_Copy constructor " << '\n';
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
FragTrap::FragTrap(std::string name)
{
    std::cout << R << "FragTrap" << EOC << " Constructor " \
        << R << "[" << name << "]" << EOC << std::endl;
    this->m_name = name;
    this->m_hit_points = 100;
    this->m_energy_points = 100;
    this->m_attack_damage = 30;
    this->printStatus();
}

/*  [F]
    Overloaded assignment operator
    
    [ Logic ]
    Check ClapTrap.cpp // Same logic.
*/
FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        this->m_hit_points = rhs.m_hit_points;
        this->m_energy_points = rhs.m_energy_points;
        this->m_attack_damage = rhs.m_attack_damage;
        std::cout << "FragTrap_duplicate of " \
            << R << "[" << this->m_name << "]" \
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
void FragTrap::attack(const std::string& targetObject)
{
    if (this->m_hit_points < 1)
    {
        std::cout << "FragTrap " << this->m_name \
            << " can't attack (Reason: Hit points < 1)" << std::endl;
        return ;
    }
    if (this->m_energy_points < 1)
    {
        std::cout << "FragTrap " << this->m_name \
            << " can't attack (Reason: Energy points < 1)" << std::endl;
        return ;
    }
    this->m_energy_points--;
    std::cout << R << "[FragTrap::attack] " << EOC \
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
    Only can be called in child class.
*/
void FragTrap::highFivesGuys(void) const
{
    std::cout << R << "[FragTrap::highFiveGuys] " << EOC \
        << this->m_name << " Hi Hi Hi Hi Hi Guys" << std:: endl;
}
