/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:30 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 11:18:31 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  [F]
    [Explanation]
    Stack don't need to use pointer  
*/
void    randomChump(std::string name)
{
    Zombie  staticZombie = Zombie(name);
    staticZombie.announce();
}
