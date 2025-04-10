/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:23:18 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/28 12:23:20 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*  [F]
    6 member functions for project.
*/
Harl::Harl()    // Constructor
{
	std::cout << "Harl: created" << std::endl; 
}

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

Harl::~Harl()   // Destructor
{
	std::cout << "Harl: distroyed" << std::endl; 
}

/*
    In method 'complain', 4 member functions are declared as an member function pointer.

    Function pointer means name of function (= address of function)
    When call the function, we should put &(reference) to find the address of function.
*/
void    Harl::complain(std::string level)
{
    // Array of function pointers to member functions of Harl class
    //  [return]  [class & (f)name]  [parameter list]
    // 1. void     Harl::(debug)     (void)
    // 2. void     Harl::(info)      (void)
    // 3. void     Harl::(warning)   (void)
    // 4. void     Harl::(error)     (void)
    // 포인터 array가 각 함수 시작 주소를 가리키고 있다.
    void (Harl::*ptr_complain[4])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Array of strings representing correspoding levels.
    std::string levels[4] =
    {
        "debug",
        "info",
        "warning",
        "error"
    };

    // Iterate through levels-array to find matching level.
    // If the input level matches a level in levels-array,
    // Call the corresponding funtion using function pointer.
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*ptr_complain[i])();
            break ;
        }
    }
}

/*  [F]
    For testing 'public & private'.
*/
// void    Harl::example(void)
// {
//     std::cout << "Example" << std::endl;
// }