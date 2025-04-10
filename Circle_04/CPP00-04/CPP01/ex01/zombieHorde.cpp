/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:44:15 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/25 13:44:16 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  [F]
    [ Condition ]
    Must allocate each zombie separately.

    [ Logic ]
    Each zombie has it's name.
    save 'int' type("N") to the 'stringstream' type("ss").
    print ss as an 'str()' type.

    [ Tip ]
    ss = stringstream // 문자열을 공백 기준으로 구분하여 stream으로 저장.
    ss.str("") == ss.str(std::string())
    Funtion to initialize stringstream.
*/
Zombie* zombieHorde(int N, std::string name)
{
    Zombie* res = new Zombie[N];
    std::stringstream   ss;

    for (int i = 0; i < N; i++)
    {
        ss << i;
        res[i].setName(name + " " + ss.str());
        res[i].announce();
        std::cout << std::endl;
        ss.str("");
    }
    return (res);
}
