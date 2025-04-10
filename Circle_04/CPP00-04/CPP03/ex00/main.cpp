/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:08:47 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/18 12:08:48 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*	[F]
	[ Rule ]
    Hit points		: Health point (HP)
					  -> No hp == died.
    Energy point	: Whenever do 'attack' or 'be repaired'
					  -> must -1 from energy points.
					  If no energy point == Can't 'attack' or 'be repaired'.
    Attack damage   : Amout of attackdamage
					  Deduct amount from hit points.
*/
int main(void)
{
	std::string str1 = "jason";
	std::string str2 = "irene";

    ClapTrap claptrap1(str1);
	std::cout << std::endl;
	ClapTrap claptrap2(str2);

	std::cout << std::endl;
	claptrap1.beRepaired(10);

	std::cout << std::endl;
	claptrap1.attack(str2);

	std::cout << std::endl;
	claptrap2.takeDamage(5);

	std::cout << std::endl;
	claptrap2.beRepaired(5);

	std::cout << std::endl;
	claptrap2.attack(str1);

	std::cout << std::endl;
	claptrap1.takeDamage(10);

	std::cout << std::endl;
	claptrap1.beRepaired(5);

	std::cout << std::endl;
	claptrap1.attack(str2);

	std::cout << std::endl;
	claptrap2.takeDamage(5);
	std::cout << std::endl;
	return (0);
}
