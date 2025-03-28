/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:35 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:36 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/* MACRO */
// Bold color definitions using ANSI
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
#include <iostream> // std::cout, std::cerr
#include <stdint.h> // uintptr_t

/* STRUCT */
// For the test in main function.
struct  Data
{
    int value;
    std::string text;
};

/* CLASS */
class Serializer
{
    private:

    public:
        /* [ OCCF ]: 4ea */
        Serializer();                                   // Default constructor
        ~Serializer();                                  // Destructor
        Serializer(const Serializer& other);            // Copy constructor
        Serializer& operator=(const Serializer& rhs);   // Overloaded assignment operator

        /* [ Methods ]: 2ea */
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
