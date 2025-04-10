/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:43 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 11:18:45 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  [F]
    [ Detail ]
    1. new
    'res' is a pointer to a Zombie object, which is allocate memory into the res.

    2. delete
    If you don't delete it, when you are finished using it, memory leak will occur.
*/
Zombie* newZombie(std::string name)
{
  Zombie *res = new Zombie(name);
  return (res);
}
