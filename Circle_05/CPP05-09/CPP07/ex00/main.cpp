/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:56:20 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 16:56:21 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

/*
    [ Goal of ex00 ]
    Make 3functions(swap, min, max).
    = can be called with any type of arguement.
    = Generic function by using template.

    [ Background knowledge ]
    1. Template (Generic code)

        < Definition >
        It's used to create generic classe and function,
        that can be called with any type of argument.
        (= int, float, double, char, string).
    
        < When >
        1. Use the same code logic across different types without relying ont specific data types.
        = 특정 데이터 타입에 의존하지 않고, 다양한 타입에서 동일한 코드 로직을 사용할 수 있다.
        2. When the tpye of parameter is changed, but want to use same function.
        = 매개변수의 타입이 바뀌었는데 동일한 함수를 재사용하고 싶을때.

        < Good points >
        1. Reusability
            Code works well for various different data types without duplicating.

        2. Type safety
            Preventing type-related errors at the compile time.

        3. Flexibility
            Easy to make the code more flexible.

        < Condition >
        For comparison, two arguments must have the same type.

    [ Memo ]
    1. ::swap
        C++98 has already the original 'swap' function.
        Computer is confused to call which function is needed.
        For this situation, put :: in front of the name of the function.
*/
void    testBasic()
{
    int a = 2;
    int b = 3;
    std::cout << "Before swap<int>: a = " << a << ", b = " << b << std::endl;

    ::swap( a, b );
    std::cout << "After swap<int>: a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Before swap<string>: c = " << c << ", d = " << d << std::endl;

    ::swap(c, d);
    std::cout << "After swap<string>: c = " << c << ", d = " << d << std::endl;

    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return ;
}

template <typename T>
void testWhatever(T a, T b)
{
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    std::cout << GRE << "[ 1. testBasic ]"<< EOC << std::endl;
    testBasic();
    std::cout << std::endl << std::endl;

    std::cout << GRE << "[ 2. testWhatever: int ]"<< EOC << std::endl;
    testWhatever(5, -1);
    std::cout << std::endl;

    std::cout << GRE << "[ 3. testWhatever: float ]"<< EOC << std::endl;
    testWhatever(5.55, 4.44);
    std::cout << std::endl;

    std::cout << GRE << "[ 4. testWhatever: char ]"<< EOC << std::endl;
    testWhatever('a', 'b');
    std::cout << std::endl;

    std::cout << GRE << "[ 5. testWhatever: string ]"<< EOC << std::endl;
    testWhatever(std::string("Jason"), std::string("Hongpei"));
    std::cout << std::endl;

    return (0);
}
