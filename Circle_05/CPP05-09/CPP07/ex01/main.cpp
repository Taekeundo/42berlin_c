/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:34:01 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 17:34:02 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/*  [F]
    [ Memo ]
    sizeof(i) / sizeof(*i)
    = 배열의 크기를 요소 개수로 변환할 때 사용
*/
int main(void)
{
    int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float f[7] = {0.5f, 1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f};
    char c[5] = {'a', 'b', 'c', 'd', 'e'};
    std::string string[3] = {"jason", "hongpei", "arthur"};

    std::cout << GRE << "[ 1. test (int) ] : size: " << sizeof(i) / sizeof(*i) << EOC << std::endl;
    iter(i, sizeof(i) / sizeof(*i), printToTerminal<int>);
    std::cout << std::endl << std::endl;

    std::cout << GRE << "[ 2. test (float) ] : size: " << sizeof(f) / sizeof(*f) << EOC << std::endl;
    iter(f, sizeof(f) / sizeof(*f), printToTerminal<float>);
    std::cout << std::endl << std::endl;

    std::cout << GRE << "[ 3. test (char) ] : size: " << sizeof(c) / sizeof(*c) << EOC << std::endl;
    iter(c, sizeof(c) / sizeof(*c), printToTerminal<char>);
    std::cout << std::endl << std::endl;

    std::cout << GRE << "[ 4. test (string) ] : size: " << sizeof(string) / sizeof(*string) << EOC << std::endl;
    iter(string, sizeof(string) / sizeof(*string), printToTerminal<std::string>);
    std::cout << std::endl << std::endl;

    return (0);
}
