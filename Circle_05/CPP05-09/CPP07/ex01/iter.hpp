/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:33:59 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 17:34:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

/* MACRO */
// Bold color definitions using ANSI for printing in the terminal.
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
// Basic
#include <string>       // std::string
#include <iostream>     // std::cout

/*
    [ Template Parameters ]
    1. typename T
        It represents the type of the array elements.

    2. typename Func
        It represents the type of the function to be applied to each element.
    
    [ Param ]
    Param(1): T array[]
    = Any type of array could be here.
    
    Param(2): size_t size
    = Size of the array

    Param(3): Func function
    = function, that will apply to each element.

    [ Role ]
    To do the 'Param(3):function' to each array index.
*/
template <typename T, typename Func>
void iter(T array[], std::size_t size, Func function)
{
    for (std::size_t i = 0; i < size; ++i)
        function(array[i]);
}

template <typename T>
void printToTerminal(const T& arg)
{
    std::cout << arg << "\t";
}

#endif
