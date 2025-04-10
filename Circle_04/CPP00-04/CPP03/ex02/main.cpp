/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:18:31 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 17:18:31 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*	[F]
	Almost same with ex01, add one more child class(= FragTrap).
*/
int main( void ) 
{
	std::string str1 = "jason";
	std::string str2 = "hongpei";
	std::string str3 = "arthur";
								// name		hp	ep	attack_damage
	FragTrap	f_trap(str1);	// jason	100	100	30
	std::cout << std::endl;
	ScavTrap	s_trap(str2);	// hongpei	100	50	20
	std::cout << std::endl;
	ClapTrap	c_trap(str3);	// arthur	10	10	0	
	std::cout << "\n------------------ "\
		"Define variable finished ------------------\n" \
		<< std::endl;

	f_trap.attack(str2);		// jason attack hongpei (-30)
	std::cout << std::endl;		// jason	100	99	30
	
	s_trap.takeDamage(20);		// hongpei	80	50	20
	std::cout << std::endl;

	c_trap.beRepaired(50);		// arthur	60	9	0
	std::cout << std::endl;

	f_trap.attack(str3);		// jason attack arthur (-30)
	std::cout << std::endl;		// jason	100	98	30

	c_trap.takeDamage(30);		// arthur	30	9	0
	std::cout << std::endl;

	s_trap.attack(str3);		// hongpei attack arthur (-20)
	std::cout << std::endl;		// hongpei	80	49	20

	c_trap.takeDamage(20);		// arthur	10	9	0
	std::cout << std::endl;

	f_trap.beRepaired(10);		// jaosn repaired (+10)
	std::cout << std::endl;		// jason	110	97	30

	s_trap.beRepaired(30);		// hongpei repaired (+30)
	std::cout << std::endl;		// hongpei	110	49	30

	c_trap.beRepaired(100);		// arthur repaired (+100)
	std::cout << std::endl;		// arthur	110	8	0

	f_trap.highFivesGuys();		// Print message (jason)
	std::cout << std::endl;

	s_trap.guardGate();			// Print message (hongpei)
	std::cout << std::endl;
	return (0);
}