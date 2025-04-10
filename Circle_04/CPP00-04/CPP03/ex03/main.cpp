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

#include "DiamondTrap.hpp"

/*	[F]
	Almost same with ex02, add one more child class(= DiamondTrap).
*/
int main( void ) 
{
	std::string str0 = "taka";
	std::string str1 = "jason";
	std::string str2 = "hongpei";
	std::string str3 = "arthur";
								// name		hp	ep	attack_damage
	DiamondTrap	d_trap(str0);	// taka		100	50	30
	std::cout << std::endl;
	FragTrap	f_trap(str1);	// jason	100	100	30
	std::cout << std::endl;
	ScavTrap	s_trap(str2);	// hongpei	100	50	20
	std::cout << std::endl;
	ClapTrap	c_trap(str3);	// arthur	10	10	0
	std::cout << std::endl;

	d_trap.whoAmi();			// print message (taka class)

	std::cout << "\n------------------ "\
		"Define variable finished ------------------\n" \
		<< std::endl;

	d_trap.attack(str1);		// taka attack jason (-30)
	std::cout << std::endl;		// taka		100	49	30

	f_trap.takeDamage(30);		// jason	70	100	30
	std::cout << std::endl;

	f_trap.attack(str2);		// jason attack hongpei (-30)
	std::cout << std::endl;		// jason	70	99	30
	
	s_trap.takeDamage(20);		// hongpei	80	50	20
	std::cout << std::endl;

	c_trap.beRepaired(50);		// arthur	60	9	0
	std::cout << std::endl;

	f_trap.attack(str3);		// jason attack arthur (-30)
	std::cout << std::endl;		// jason	70	98	30

	c_trap.takeDamage(30);		// arthur	30	9	0
	std::cout << std::endl;

	s_trap.attack(str3);		// hongpei attack arthur (-20)
	std::cout << std::endl;		// hongpei	80	49	20

	c_trap.takeDamage(20);		// arthur	10	9	0
	std::cout << std::endl;

	s_trap.attack(str0);		// hongpei attack taka (-20)
	std::cout << std::endl;		// hongpei	80	48	20

	d_trap.takeDamage(20);		// taka		80	49	30
	std::cout << std::endl;

	d_trap.beRepaired(30);		// taka repaired (+30);
	std::cout << std::endl;		// taka		110	49	30

	f_trap.beRepaired(40);		// jason repaired (+40)
	std::cout << std::endl;		// jason	110	97	30

	s_trap.beRepaired(30);		// hongpei repaired (+30)
	std::cout << std::endl;		// hongpei	110	48	30

	c_trap.beRepaired(100);		// arthur repaired (+100)
	std::cout << std::endl;		// arthur	110	8	0

	d_trap.whoAmi();			// print message (taka class)
	std::cout << std::endl;

	f_trap.highFivesGuys();		// Print message (jason class)
	std::cout << std::endl;

	s_trap.guardGate();			// Print message (hongpei class)
	std::cout << std::endl;
	return (0);
}