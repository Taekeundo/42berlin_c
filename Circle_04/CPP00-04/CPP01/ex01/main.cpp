/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:43:54 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 13:43:56 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  [F]
    [ Propose of subject ]
    Last in -> First out.

    [ Background ]
    object array
        Zombie Zombies[10]; // declare directly.

    object pointer
        Zombie *Zombies = new Zombie[10]; // using pointer.
    
    [ ETC ]
    horde: group, many of them
*/
int main(void)
{
    std::cout << "[ Creating a Horde of " << NUM_ZOMBIE << " Zombies ]"
        << std::endl;
    Zombie *tmp =  zombieHorde(NUM_ZOMBIE, "jason");
    std::cout << "[ Destroying a Horde of " << NUM_ZOMBIE << " Zombies ]"
        << std::endl;
    delete[] tmp;
    return (0);
}
