/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:07:05 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/23 10:07:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*  [F]
	Default constructor

    [ Role ]
    Initialize three private member variables, when it's called.
*/
ClapTrap::ClapTrap(void) :m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
    std::cout << "Default constructor called from the " \
        <<  G << "ClapTrap" << EOC << " class" << std::endl;
}

/*  [F]
    Destructor

    [ Goal ]
    Print "Destructor" & "Name of current object" & newline.
*/
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor " << G << this->getName() << EOC << std::endl;
}

/*  [F]
    Copy constructor

    [ Role ]
    Operator overloading (User defined)
    = Copy all data from "rhs object(param)" to "current object(this)"."
*/
ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
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
ClapTrap::ClapTrap(std::string name)
{
    std::cout << G << "ClapTrap" << EOC << " Constructor " \
        << G << "[" << name << "]" << EOC << std::endl;
    this->m_name = name;
    this->m_hit_points = 10;
    this->m_energy_points = 10;
    this->m_attack_damage = 0;
    this->printStatus();
}

/*  [F]
    Assignment operator (Overloaded)

    [ Definition ]
    Operator overloading (User defined)
    = From now on '=' works as i defined like below function.

    [ Param ]
    rhs // const
    "I will not modify the state of the object." -> "Read Only"
    = "객체의 상태를 수정하지 않겠다." -> "읽기 전용"

    Guarantees that the object is only read (loaded) and not modified.
    = 객체를 읽기(불러오기)만 하고 수정하지 않는다는 것을 보장.

    [ Goal ]
    Copy all data from rhs(param) to current object.

    [ Return ]
    Return a reference to the current object.
*/
ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        this->m_hit_points = rhs.m_hit_points;
        this->m_energy_points = rhs.m_energy_points;
        this->m_attack_damage = rhs.m_attack_damage;
    }
    return (*this);
}

/*  [F]
    [ Role ]
    Get the name from the "current object(= this)" and return it.

    [ Memo ]
    Const function
    (ex) getName(void) const
    = Can't adjust(modify) the status(value) of object.
    = 객체의 상태를 변경할 수 없음

    = const object can onlt call the const function.
    = const 객체는 const 멤버 함수만 호출할 수 있다.
*/
std::string	ClapTrap::getName(void) const
{
    return (this->m_name);
}

/*  [F]
    [ Role ]
    Print status of current object.
*/
void ClapTrap::printStatus() const
{
    std::cout << this->m_name << "'s current hit points   : " << this->m_hit_points << std::endl;
    std::cout << this->m_name << "'s current energy points: " << this->m_energy_points << std::endl;
    std::cout << this->m_name << "'s current attack damage: " << this->m_attack_damage << std::endl;
}

/*  [F]
    [ Role ]
    Attack target object(param).

    [ Memo ]
    if object attacks other object, 1 energy point is deducted.

    [ Required message to be printed ]
    ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/
void ClapTrap::attack(const std::string& targetObject)
{
    if (this->m_hit_points < 1)
    {
        std::cout << this->m_name << " can't attack (Reason: Hit points < 1)" << std::endl;
        return ;
    }
    if (this->m_energy_points < 1)
    {
        std::cout << this->m_name << " can't attack (Reason: Energy points < 1)" << std::endl;
        return ;
    }
    this->m_energy_points--;
    std::cout << G << "[ClapTrap::attack] " << EOC << this->m_name << R \
                << " attacks " << EOC << targetObject \
                << "!" << Y << " (energy point -1)" << EOC \
                << std::endl;
    this->printStatus();
}

/*  [F]
    [ Role ]
    Deduct(= minus) "damagePoints(param)" from the current object's "hit points".

    [ Required message to be printed ]
    ClapTrap <name> takes damage, causing <amount> points of damage!
*/
void ClapTrap::takeDamage(unsigned int damagePoints)
{
    if (this->m_hit_points < 1)
    {
        std::cout << this->m_name << " can't take damage (Reason: Hit points < 1)" << std::endl;
        return ;
    }
    if (this->m_energy_points < 1)
    {
        std::cout << this->m_name << " can't take damage (Reason: Energy points < 1)" << std::endl;
        return ;
    }
    this->m_hit_points = this->m_hit_points - damagePoints;
    std::cout << G << "[ClapTrap::takeDamage] " << EOC \
        << this->m_name << R << " takes damage" << EOC \
        << ", causing " << R << damagePoints << EOC \
        << " points of damage!" << std::endl;
    this->printStatus();
}

/*  [F]
    [ Role ]
    Add(= plus) "repairPoints(param)" to the current object's "hit points".

    [ Memo ]
    When receiving repairs, 1 energy point is deducted.

    [ Required message to be printed ]
    ClapTrap <name> is repairing and got <amount> points back!
*/
void ClapTrap::beRepaired(unsigned int repairPoints)
{
    if (this->m_hit_points < 1)
    {
        std::cout << this->m_name << " can't be repaired (Reason: Hit points < 1)" << std::endl;
        return ;
    }
    if (this->m_energy_points < 1)
    {
        std::cout << this->m_name << " can't be repaired (Reason: Energy points < 1)" << std::endl;
        return ;
    }
    this->m_hit_points = this->m_hit_points + repairPoints;
    this->m_energy_points--;
    std::cout << G << "[ClapTrap::beRepaired] " << EOC \
        << this->m_name << " is " << G \
        << "repairing" << EOC << " and got " \
        << G << repairPoints << EOC << " points!" \
        << Y << " (energy point -1)" << EOC \
        << std::endl;
    this->printStatus();
}