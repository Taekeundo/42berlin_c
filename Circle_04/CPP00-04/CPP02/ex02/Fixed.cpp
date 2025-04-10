/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:36:59 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:37:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  [F]
	Default constructor

	Initialize private member function, when it's called.
*/
Fixed::Fixed()
{
    this->m_fixed_point = 0;
}

/*  [F]
    Destructor called

	Initialize private member function, when it's called.
*/
Fixed::~Fixed()
{
    this->m_fixed_point = 0;
}

/*  [F]
    Copy constructor
    User defined, copy overloading.

    [ Definition ]
    Initialize a new Fixed object as a copy of another Fixed object.
    = 다른 Fixed 객체를 복사하여 새로운 Fixed 객체를 초기화.

	If wants to know more, check ex01, CPP01.
*/
Fixed::Fixed(const Fixed &rhs)
{
    this->setRawBits(rhs.getRawBits());
}

/*  [F]
    Copy assignment operator
    User defined, Operator overloading.

	[ Definition ]
    Assigns the value from another Fixed object to this object.
    = 다른 Fixed 객체의 값을 이 객체에 할당.

	If wants to know more, check ex01, CPP01.
*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->m_fixed_point = rhs.getRawBits();
    return (*this);
}

/*  [F]
    Int constructor called

    [ Definition ]
    Constructor, converts (int) to (fixed point).

    [ Logic ]
    fixedInt.m_fixed_point = i_val << m_frac_bits;
                                   << 8
                                   * 2^8
                                   * 256

    If wants to know more, check ex01, CPP01.
*/
Fixed::Fixed(const int i_val)
{
    this->m_fixed_point = (i_val << this->m_frac_bits);
}

/*  [F]
    Float constructor called

    [ Definition ]
    Constructor, converts (float) to (fixed point).

    [ Logic ]
    fixedFloat.m_fixed_point = roundf(f_val * (1 << m_frac_bits));
                                            * (1 << 8)
                                            * (1 * 2^8)
                                            * (256)

	If wants to know more, check ex01, CPP01.
*/
Fixed::Fixed(const float f_val)
{
    this->m_fixed_point = roundf(f_val * (1 << this->m_frac_bits));
}

/*  [F]
    Member functions (1)

    [ Definition ]
    Return the "m_fixed_point" from the private member variable.
    = private 멤버 변수 "m_fixed_point" 값을 반환.

	If wants to know more, check ex01, CPP01.
*/
int Fixed::getRawBits( void ) const
{
    return (this->m_fixed_point);
}

/*  [F]
    Member function (2)

    [ Definition ]
    Set the "m_fixec_point" with the param(="raw").
    = 전달된 매개변수 "raw" 값을 "m_fixed_point"에 설정.

	If wants to know more, check ex01, CPP01.
*/
void Fixed::setRawBits( int const raw )
{
    this->m_fixed_point = raw;
}

/*  [F]
    Member function (3)

    [ Definition ]
    Converts object's (m_fixed_point)value to (float)type.
    Reverse process of the "Float constructor".

	If wants to know more, check ex01, CPP01.
*/
float Fixed::toFloat( void ) const
{
    return ((float)this->m_fixed_point / (1 << this->m_frac_bits));
}

/*  [F]
    Member function (4)

    [ Definition ]
    Converts object's (m_fixed_point)value to (int)type.
    Reverse process of the "Int constructor".

	If wants to know more, check ex01, CPP01.
*/
int Fixed::toInt( void ) const
{
    return (this->m_fixed_point >> this->m_frac_bits);
}

/*	[F]
	[ Definition ]
	Checks whether the current Fixed object is greater
	than another Fixed object by comparing their (m_fixed_point).

	[ Memo ]
	this->getRawBits()	: Accessing the m_fixed_point of the current Fixed object.
	rhs.getRawBits()	: Accessing the m_fixed_point of the (param)Fixed object.

    Same logic with below 5 functions (<, >=, <=, ==, !=)
*/
bool Fixed::operator>(const Fixed &rhs) const
{
    if (this->getRawBits() > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	else
		return (false);
}

/*  [F]
    [ Definition ]
    Do arithmetic operating with float type.

    Same logic with below 3 functions (-, *, /)
*/
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed res(this->toFloat() + rhs.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed res(this->toFloat() - rhs.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed res(this->toFloat() * rhs.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed res(this->toFloat() / rhs.toFloat());
	return (res);
}

/*	[F]
	Pre-increment operator (b = ++a)
    Pre-decrement operator (b = --a)

    [ Logic ]
    First plus value +1 -> return.
    First minus value -1 -> return.

    [ Easy to understand ]
    int a = 3;
    ++a = 6;
    std::cout << a << std::endl;
    = 6 printed.
    = a: 3 -> 4 -> 6.

    int a = 3;
    a++ = 6;
    = compile error.
*/
Fixed& Fixed::operator++()
{
    ++this->m_fixed_point;
    return (*this);
}

Fixed& Fixed::operator--()
{
    --this->m_fixed_point;
    return (*this);
}

/*	[F]
	Post-increment operator (b = a++)
    Post_decrement operator (b = a--)

    [ Background ]
    1. Overloading
        C++에서 함수 오버로딩을 통해 같은 이름의 함수가 여러 개 정의될 수 있다.
        이 경우 각 함수는 서로 다른 매개변수를 가져야한다.
        이를 함수 오버로딩이라고 한다.

        operator++라는 이름의 함수가 이미 정의되어있다.
        그래서 구별되기 위해 사용하진 않지만 param으로서 int를 signiture로 사용해준다.

    2. Post-operator.
        후위 연산자는 현재상태를 리턴 한 뒤 작업을 실행한다.
        리턴값은 항상 처음 상태여야 한다.

    [ Logic ]
    1. declare 'result' object and save current status of object(= 'Fixed').
    2. change member variable from the current object.
    3. return (previous) object that saved in 'res'.

    [ Why declare 'res' variable? ]
    후위 증가, 감소 연산자는 객체를 증가시키기 전에 현재 상태의 값을 반환해야 하기 때문.
    
    [ Easy to understand ]
    1. Take the photo.
    2. Change condition.
    3. Submit the photo from number 1.
*/
const Fixed Fixed::operator++(int)
{
    Fixed res(*this);
    ++this->m_fixed_point;
    return (res);
}

const Fixed Fixed::operator--(int)
{
    Fixed res(*this);
    --this->m_fixed_point;
    return (res);
}

/*  [F]
    [ Definition ]
    Check whether param(1) is greater or less than param(2).
    Return an appropriate result (= min or max)
    among the two Fixed objects.

    [ Background ]
    Difference "const"min function & "normal"min function.

    "const 객체는 const 함수만 호출할 수 있다.

    Both (a, b) are const object -> only call 'const'function.
    There is nothing for 'const' functions.
    The objects are not modified within the function.
    So just use param directly with & for comparing each other.
*/
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if ((a < b) == true)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if ((a > b) == true)
		return (a);
	else
		return (b);
}

/*  [F]
    [ Definition ]
    Comparing the (m_fixed_point) stored within the Fixed objects (a, b), params.
    By using [f] getRawBits() member function comparing value of (m_fixed_point)
    and returns an appropriate result (= min or max).
*/
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

/*  [F]
    Output stream operator
    User defined, Operator overloading.

    [ Definition ]
    Overloads the << operator to allow Fixed objects to be output to streams.
    = Fixed 객체를 스트림에 출력할 수 있도록 '<< 연산자'를 오버로딩.

	If wants to know more, check ex01, CPP01.
*/
std::ostream& operator<<(std::ostream& out, const Fixed& _fixed)
{
    out << _fixed.toFloat();
    return (out);
}