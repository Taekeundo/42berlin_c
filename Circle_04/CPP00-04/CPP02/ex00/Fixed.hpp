/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:34:59 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:35:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

/*  [F]
    [ Background knowledge ]
    1. copy constructor
     - Default copy constructor
        If the copy constructor is not customized by the programmer
        the default copy constructor is automatically defined and used.
        = 복사 생성자가 별도로 사용자 정의 되어있지않을 경우 디폴트 복사생성자 자동정의.
        
        Use Shallow copy -> copy the address only like pointer.
        = 디폴트는 얕은 복사만 한다.
    
     - User defined copy constructor
        Can use 'Deep' copy -> allocated memory for copying the value.
        = 기존 복사 생성자(=)를 재정의.
        = 필요한 경우 깊은 복사를 수행하도록 정의할 수 있다.

    2. copy assignment operator
     - Default copy assginment operator
        = 별도로 정의되지 않은 경우, 컴파일러가 자동으로 디폴트 복사 대입 연산자를 생성.

        Use Shallow copy -> copy the address only like pointer.
        = 디폴트는 얕은 복사만 한다.

     - User defined copy assignment operator
        Can use 'Deep' copy -> allocated memory for copying the value.
        = 기존 대입 연산자(=)를 재정의.
        = 필요한 경우 깊은 복사를 수행하도록 정의할 수 있다.

    [ Tipp ]
    rhs : right hand side.
*/
class Fixed
{
    private:
        int m_fixed_point;
        static const int m_frac_bits = 8;

    public:
        Fixed();                                // Default constructor
        ~Fixed();                               // Destructor
        Fixed(const Fixed &rhs);                // Copy constructor
        Fixed& operator=(const Fixed &rhs);     // Copy assignment operator

        int getRawBits(void) const;             // Member function (1)
        void setRawBits(int const raw);         // Member function (2)
};

#endif