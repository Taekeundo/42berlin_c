/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:37:35 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/28 14:37:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*  [F]
    Same logic but using 'switch'.
*/
int	main (int argc, char **argv) 
{
	Harl harl;

    if (argc != 2)
        std::cout << "command : ./harlFilter [ DEBUG | INFO | WARNING | ERROR]" << std::endl;
	else
        harl.harlFilter(argv[1]);
    return (0);
}
