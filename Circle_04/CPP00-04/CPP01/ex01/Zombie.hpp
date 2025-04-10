/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:44:11 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 13:44:13 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#define NUM_ZOMBIE  5   // Random number.

#include <iostream>     // std::cout, std::endl
#include <string>       // std::string()
#include <sstream>      // std::stringstream

/*  [F]
*/
class Zombie
{
    
    public:                                 // [ Member-function: method ]
        Zombie();                           // Constructor
        void    setName(std::string name);  // Action 1
        void    announce(void);             // Action 2
        ~Zombie();                          // Destructor

    private:                                // [ Member variable ]
        std::string m_name;                 // Name of zombie

};

Zombie* zombieHorde(int N, std::string name);

#endif
