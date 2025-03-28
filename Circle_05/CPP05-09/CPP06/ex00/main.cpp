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

#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "Error: Format of the input is inconrrect" << EOC << std::endl
        << "ex) ./convert [String type input]" << std::endl;
    }
    else
    {
        try
        {
            Converter::convert(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}
