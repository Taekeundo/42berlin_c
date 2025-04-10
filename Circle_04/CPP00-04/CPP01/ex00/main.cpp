/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:25 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 11:18:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  [F]
    [ Propose of subject ]
    Determein what case it’s better to allocate the zombies on the stack or heap.

    [ Background ]
    <stack>
        1. LIFO(Last-In, First-Out) structure.
        2. parameters || local variables are located.
        3. Automatically destroyed when it leaves from the scope of the function.
        4. Access instances through the (.) operator. // dot

    <heap>
        1. new // dynamic memory allcation in C++
        2. Can be shared across all processes.
        3. delete // free in C++, prevent to occur memory leak.
        4. Access instances through the (->) operator. // arrow 

    [ Process ]
    "zombie1"                       C++            C
        1. Make zombie.         // new();        malloc
        2. Make zombie sounds.  // announce();   action
        3. Delete zombie1.      // delete();     free

    "zombie2"
        1. Make, make the sounds all together. // randomChump();
    
    [ Memory layout ]
    "heap"
        zombie1: It can be used in other functions.
    "static"
        zombie2: Only used in function.
*/
int main(void)
{
    Zombie  *heapZombie = newZombie("zombie1");
    heapZombie->announce();
    delete (heapZombie);    // Must use 'delete', after finishing heap.
    std::cout << std::endl;
    randomChump("zombie2");
    std::cout << "test" << std::endl;
    return (0);
}
