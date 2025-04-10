/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:08:16 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 12:08:17 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout, std::endl
#include <string>       // std::string()

/*  [F]
    [ Goal ]
    Learn about (string, pointer, reference)'s address & value.

    [ Reference ]
    1. Modify Variables
        References allow functions to modify the original variable directly.
    2. Avoid Copying
        Avoid the overhead of copying large objects when passing them to functions.
    3. Syntactic Clarity
        References provide clearer and more readable code compared to pointers.
    4. ETC
        Reference is the nickname.
        When you want to change the value of a variable from another function,
        you can use a reference as a parameter to modify the value.
    
    stringREF은 str의 별명이며 같은 메모리 공간을 참조한다.
    참조자를 통해 값을 변경하면 메모리 공간을 같이 쓰는 변수의 값도 변경된다.

    '양배추'라고 불리우던 사람이 '조세호'라고 불리울뿐
    이름만 달라졌지 특성을 포함한 그 사람은 동일인물이다.
*/
int main(void)
{
    // Declare & Initialize
    std::string string = "HI THIS IS BRAIN";    // Declare "string"
    std::string *stringPTR = &string;           // Declare "pointer"
    std::string &stringREF = string;            // Declare "reference"

    // Print address
    std::cout << "Address of string     :" << &string << std::endl;
    std::cout << "Address of stringPTR  :" << stringPTR << std::endl;
    std::cout << "Address of stringREF  :" << &stringREF << std::endl;

    // Print value
    std::cout << "Value of string       :" << string << std::endl;
    std::cout << "Value of stringPTR    :" << *stringPTR << std::endl;
    std::cout << "Value of stringREF    :" << stringREF << std::endl;
    return (0);
}
