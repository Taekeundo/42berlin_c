/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:17:44 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/24 11:41:20 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*	[F]
	[ Background ]
	Parent class: ClapTrap
			  |
	Child class	: ScavTrap

	When call 'ScavTrap' class, it's because child from 'ClapTrap',
	must call 'parent' class first and then we can use 'child' class.
	= !! 자식 클래스의 객체를 생성할 때 부모 클래스의 생성자가 먼저 호출 !!
*/
int main( void ) 
{
	std::string str1 = "jason";
	std::string str2 = "hongpei";
	std::string str3 = "arthur";
								// name		hp	ep	attack_damage
	ScavTrap scavtrap1(str1);	// jason 	100	50	20
	std::cout << std::endl;
	ScavTrap scavtrap2(str2);	// hongpei	100	50	20
	std::cout << std::endl;
	ClapTrap claptrap1(str3);	// arthur	10	10	0
	std::cout << std::endl;

	scavtrap1.attack(str2);		// jason attack hongpei (-20)
	std::cout << std::endl;		// jason	100	49	20

	scavtrap2.takeDamage(20);	// hongpei	80	50	20
	std::cout << std::endl;

	claptrap1.beRepaired(20);	// arthur	30	9	0
	std::cout << std::endl;

	scavtrap1.attack(str3);		// jason attack arthur (-20)
	std::cout << std::endl;		// jason	100	48	20

	claptrap1.takeDamage(20);	// arthur	10	9	0
	std::cout << std::endl;

	scavtrap2.beRepaired(10);	// hongpei repaired (+10)
	std::cout << std::endl;		// hongpei	90	49	20

	claptrap1.beRepaired(10);	// arthur repaired (+10)
	std::cout << std::endl;		// arthur	20	8	0

	scavtrap1.guardGate();		// Print message (jason)
	std::cout << std::endl;
	return (0);
}
