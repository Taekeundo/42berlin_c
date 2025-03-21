/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:02:29 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/20 16:02:29 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int>          intArray(5);
    Array<float>        floatArray(5);
    Array<double>       doubleArray(5);
    Array<char>         charArray(5);
    Array<std::string>  stringArray(5);

    for (int i = 0; i < 5; i++)
    {
        intArray[i] = i;
        floatArray[i] = i + 0.3;
        doubleArray[i] = i + 0.5;
    }

    std::cout << GRE << "[ test: int, float, double ]" << EOC << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        std::cout << "floatArray[" << i << "] = " << floatArray[i] << std::endl;
        std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
        std::cout << std::endl;
    }

    std::cout << GRE << "[ test: char, string ]" << EOC << std::endl;
    charArray[0] = 'a';
    charArray[1] = 'b';
    charArray[2] = 'c';
    charArray[3] = 'd';
    charArray[4] = 'e';

    stringArray[0] = "Hi my";
    stringArray[1] = "name is";
    stringArray[2] = "Jason";
    stringArray[3] = "nice to";
    stringArray[4] = "meet you";

    for (int i = 0; i < 5; i++)
    {
        std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
        std::cout << std::endl;
    }

    std::cout << GRE << "[ test: exceptional case ]" << EOC << std::endl;
    try
    {
        intArray[6] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << EOC << std::endl;
    }
    return 0;
}
