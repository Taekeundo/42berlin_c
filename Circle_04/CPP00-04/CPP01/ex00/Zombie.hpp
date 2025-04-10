/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:36 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 11:18:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream> //std::cout, std::endl

/*  [F]
*/
class   Zombie
{
    public:
        // Basic: 2ea
        Zombie(std::string name);       // Constructor
        ~Zombie();                      // Destructor

        // Methode: 1ea
        void announce(void);            // Action

    private:
        // Member variable: 1ea 
        std::string zombieName;             // Name of zombie
};

void    randomChump(std::string name); // STACK
Zombie* newZombie(std::string name);   // HEAP

#endif
