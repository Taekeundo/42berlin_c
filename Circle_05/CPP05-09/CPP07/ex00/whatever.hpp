/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:26 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 16:56:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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

template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return ((a < b) ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return ((a > b) ? a : b);
}

#endif
