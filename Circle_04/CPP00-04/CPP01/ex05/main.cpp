/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:23:27 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/28 12:23:31 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*  [F]
    [ Function pointer ]
    1. Way to declare
    return type     (*funtionPointer's name)(parameter's type, parameter's type);
    (ex) void    (*ptr)(std::string s1, std::string s2);

    [ Member function pointer ]
    1. Way to declare
    [return type]     (*[class name]::[member function's name])([parameter's list])

        void    Harl::complain(std::string level)
    ------------------------------------------------------------------------
    2. Way to assign the funcion to function pointer
    [member function's name] = &[class name]::[member function's name];

        Not here.
    ------------------------------------------------------------------------
    3. Call the function insied of class // 클래스 내부에서 함수 호출
    (this->*[member function pointer's name])([parameter's list])

        Not here.
    ------------------------------------------------------------------------
    4. Call the function ouside of class // 클래스 외부에서 함수 호출
     a. 인스턴스 생성: [클래스명]	[인스턴스명] = [생성자];
     b. 인스턴스 활용 함수 호출: ([인스턴스명].*[멤버 함수 포인터명])([매개변수 목록]);

        harl.complain("debut");
    ------------------------------------------------------------------------

    [ Using parameter ]
    -> Parameter is saved in 'STACK' onlt during the function executed.
    -> Memory efficient way.

    [ Structure ]
    Class
        private
            [level]
            f) void Harl::debug(void)
            f) void Harl::infor(void)
            f) void Harl::warning(void)
            f) void Harl::error(void)

        public
            f) void Harl::complain(std::string level)

    [ logic ]
    1. Define the [class]'s object (= "harl")
    2. Call the method(= "complain").
        -->  "f) complain": [class(= "Harl")'s public function].
        -->  주어진 오류 메시지 타입에 따라 적절한 함수를 호출.
        2-1. Define function array for "function pointer"
        2-2. Define string array for "error message"
        2-3. Comparing "error message" with the (function name == function pointer)
        2-4. Calls the appropriate function based on the given error message type, using function pointer.
*/
int main()
{
    Harl harl;

    harl.complain("debug");     // harl::debug();   but can't call
    harl.complain("info");      // harl::info();    but can't call
    harl.complain("warning");   // harl::warning(); but can't call
    harl.complain("error");     // harl::error();   but can't call

    // harl.example();
    // The 'example' function isn't defined in the Harl class,
    // but if it were defined as a pubic memeber function,
    // It could me directly called using the dot(.) operator.
    return (0);
}
