/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:37:25 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/28 14:37:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*  [F]
    6 member functions for project.
*/
Harl::Harl(){}  // Constructor

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
    << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
    << std::endl << std::endl;
}

Harl::~Harl(){} // Destructor

/*  [F]
    Same logit but using 'switch'.

    [switch]
    up to 'i', execute correspoding function.
    No break? -> keep executing.
    meet break? -> exit from the loop.
*/
void    Harl::harlFilter(std::string level)
{
    void (Harl::*functions[4])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
            break ;
        i++;
    }

    if (i == 4)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    else
    {
        switch (i)
        {
            case 0:
                (this->*functions[0])();
            case 1:
                (this->*functions[1])();
            case 2:
                (this->*functions[2])();
            case 3:
                (this->*functions[3])();
                break;
        }
    }
}

