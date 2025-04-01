/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:03 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:04 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "Error: Format of the input is inconrrect" << EOC << std::endl
        << "ex) ./convert [String type input]" << std::endl;
    }
    else
    {
        std::cout << ScalarConverter(argv[1]);
    }
    return (0);
}
