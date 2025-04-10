/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:34:50 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:34:53 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor
    Intialize list
        Intialize private member variable to '0',
        at the same time when this function is called.
*/
Fixed::Fixed(): m_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*  Copy constructor (User defined)

    param: rhs
        const사용 -> "객체의 상태를 수정하지 않겠다." -> "읽기 전용"
        객체를 읽기(불러오기)만 하고 수정하지 않는다는 것을 보장.

    shallow copy
        &, reference사용 -> 얕은 복사는 객체의 멤버 변수들만 복사.
        int type 데이터만 복사되기에 얕은복사를 사용해서 효율성을 높였다.
    
    Why here to use shallow copy(&)?
        클래스의 단순성과 효율성 때문.
        int type 데이터만을 복사하면 되므로 얕은 복사가 적절.
*/
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

/*  Copy assignment operator (User defined -> Operator overloading)

    param: rhs
        const사용 -> "객체의 상태를 수정하지 않겠다." -> "읽기 전용"
        객체를 읽기(불러오기)만 하고 수정하지 않는다는 것을 보장.

    shallow copy
        &, reference사용 -> 얕은 복사는 객체의 멤버 변수들만 복사.
        int type 데이터만 복사되기에 얕은복사를 사용해서 효율성을 높였다.
    
    Why here to use shallow copy(&)?
        클래스의 단순성과 효율성 때문.
        int type 데이터만을 복사하면 되므로 얕은 복사가 적절.
    
    Fixed&      :   Fixed 클래스의 객체에 대한 참조.
    operator=   :   대입 연산자(=)를 오버로딩하는 함수.
*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->m_fixed_point = rhs.getRawBits();
    return (*this);
}

/* Destructor called */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* Member functions (1), (2) */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->m_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    this->m_fixed_point = raw;
}