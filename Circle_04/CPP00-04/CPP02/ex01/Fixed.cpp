/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:36:24 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/09 14:36:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  [F]
    Default constructor
    
    [ Definition ]
    Intialize private member variable (= 'm_fixed_point) to '0',
    when this function is called.
*/
Fixed::Fixed(): m_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*  [F]
    Destructor called
*/
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

    (Example)
    int i_val = 5;
    = i_val << 8       // Shifting 8times to the left
    = 5 * 256
    = 1280 (decimal) to binary
    
        1280 / 2 = 640  (0)
        640  / 2 = 320  (0)
        320  / 2 = 160  (0)
        160  / 2 =  80  (0)
        80   / 2 =  40  (0)
        40   / 2 =  20  (0)
        20   / 2 =  10  (0)
        10   / 2 =   5  (0)
        5    / 2 =   2  (1)
        2    / 2 =   1  (0)
        1    / 2 =   0  (1)

        = 10100000000       // 11 digits
        = 0000010100000000  // 16 digits (16비트로 확장)
        
        = 00000101       +      00000000
        = interger part  +      Decimal part (소수점 이하 부분을 8비트로 고정)

    !! this->m_fixed_point = 1280 !!

    [ Conclusion ]
    고정 소수점 형식은 정수와 소수점을 특정 비트 수로 고정하여 표현.
    뒤에서부터 8비트(자리, digits)를 소수 부분으로 고정하여 정밀도를 유지.

    [ When used ]
    1. 정밀한 소수점 이하 계산이 필요할 때        1 = 256, 5 = 1280, 1.5 = 384
    2. 일관된 표현 형식을 유지하기 위해           xx.0000 + xx.0000
    3. 특정 단위로 변환할 때 간편하게 표현 가능    1m -> 100cm
*/
Fixed::Fixed(const int i_val)
{
    std::cout << "Int constructor called" << std::endl;
    this->m_fixed_point = (i_val << this->m_frac_bits);
}

/*  [F]
    Float constructor called

    [ Definition ]
    Constructor, converts (float) to (fixed point).

    [ Background ]
    roundf() : rounding off result to the nearest integer.
               Must rounding off on the first decimal digit.

    [ Logic ]
    fixedFloat.m_fixed_point = roundf(f_val * (1 << m_frac_bits));
                                            * (1 << 8)
                                            * (1 * 2^8)
                                            * (256)
                                                
    (Example)
    float f_val = 1.6f;
    = roundf(f_val * (1 << 8))
    = roundf(1.6 * 256)
    = roundf(409.6) // 반올림 (round off)
    = 410 (decimal) to binary
        
        410 / 2 = 205   0
        205 / 2 = 102   1
        102 / 2 = 51    0
        51  / 2 = 25    1
        25  / 2 = 12    1
        12  / 2 = 6     0
        6   / 2 = 3     0
        3   / 2 = 1     1
        1   / 2 = 0     1

        = 110011010             // 9 digits
        = 0000000 + 110011010   // 16 digits (16비트로 확장)
    
    !! this->m_fixed_point = 410 !!
 */
Fixed::Fixed(const float f_val)
{
    std::cout << "Float constructor called" << std::endl;
    this->m_fixed_point = roundf(f_val * (1 << this->m_frac_bits));
}

/*  [F]
    Copy constructor
    User defined, copy overloading.

    [ Definition ]
    Initialize a new Fixed object as a copy of another Fixed object.
    = 다른 Fixed 객체를 복사하여 새로운 Fixed 객체를 초기화합니다.

    [ Logic ]
    1. Use getRawBits() on the rhs object to obtain its m_fixed_point value.
    = rhs 객체에서 getRawBits()를 사용하여 m_fixed_point 값을 가져.

    2. Set this value to the current object's m_fixed_point using setRawBits().
    = 가져온 m_fixed_point을 setRawBits()를 사용하여 현재 객체의 m_fixed_point에 설정.
*/
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

/*  [F]
    Copy assignment operator
    User defined, Operator overloading.

    [ Definition ]
    Assigns the value from another Fixed object to this object.
    = 다른 Fixed 객체의 값을 이 객체에 할당.

    [ Logic ]
    1. Check for self-assignment.
    = 자기 자신에 할당하는 경우를 확인합니다.
       if (this != &rhs)
       = 만약 현재 객체(this)와 rhs가 다르다면 (자기 자신이 아니라면)
    2. Use getRawBits() on the rhs object to obtain its m_fixed_point value.
    = rhs 객체에서 getRawBits()를 사용하여 m_fixed_point 값을 가져.
    3. Assign this value to the current object's m_fixed_point.
    = 가져온 m_fixed_point을 현재 객체의 m_fixed_point에 할당.
    5. Return the current object by reference.
    = 현재 객체 참조로 반환.
*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->m_fixed_point = rhs.getRawBits();
    return (*this);
}

/*  [F]
    Member functions (1)

    [ Definition ]
    Return the "m_fixed_point" from the private member variable.
    = private 멤버 변수 "m_fixed_point" 값을 반환.
*/
int Fixed::getRawBits(void) const
{
    return (m_fixed_point);
}

/*  [F]
    Member function (2)

    [ Definition ]
    Set the "m_fixec_point" with the param(="raw").
    = 전달된 매개변수 "raw" 값을 "m_fixed_point"에 설정.
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

    [ Example ]
    Float constructor
        f_val = 1.6f
        1.6 * 256 = 409.6
        roundf(409.6) = 410
        m_fixed_point = 410
    
    toFloat
        (float)m_fixed_point / (1 << this->m_frac_bits)
        (float)410 / 256
        = 1.60156
    
    [ Memo ]
    1. approximation
        1.6f != 1.60156
        = 동작 과정을 통해 fixed_point의
          approximation(근사값)의 한계점을 이해할 수 있다.

    2. const
        why do i need to put 'const' at the end of the function's name?

        class Fixed {
        private:
            int m_fixed_point;
            static const int m_frac_bits = 8;

        public:
            // const가 붙은 함수
            float toFloat(void) const {
                return ((float)m_fixed_point / (1 << m_frac_bits));
            }

            // const가 붙지 않은 함수
            float toFloatNonConst(void) {
                return ((float)m_fixed_point / (1 << m_frac_bits));
            }
        };

        int main()
        {
            Fixed obj1;                 // 일반 객체
            const Fixed obj2;           // const 객체

            // const가 붙은 함수 호출
            obj.toFloat();              // OK: 일반 객체에서 호출 가능
            constObj.toFloat();         // OK: const 객체에서도 호출 가능

            // const가 붙지 않은 함수 호출
            obj.toFloatNonConst();      // OK: 일반 객체에서 호출 가능
            constObj.toFloatNonConst(); // 에러: const 객체에서는 호출 불가

            return 0;
        }

        const function
        1. Not change the status of object.
        2. Can be called by 'const'object(= 'obj2') and normal object.
        
        non-const function
        1. Can change the status of object.
        2. Can't be called by 'const'object(= 'obj2').

        = Const object only can call the const functions.
        = Non const object can call every functions, whether the function is const or not.

    [ toFloat 함수가 const 함수여야 하는 이유 ]
    'toFloat' function is only called by below function 'operator<<'.
        
        std::ostream& operator<<(std::ostream& out, const Fixed& m_fixed);

    'operator<<'s 2nd parameter is const "const Fixed& m_fixed".
    const object can call only const member function.
    So 'toFloat' must be const function.
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

    [ Example ]
    Int constructor
        i_val = 5;
        5 << 8bits
        5 * 256 = 1280
        m_fixed_point = 1280

    toInt
        m_fixed_point >> 8bits
        1280 >> 8bits
        1280 / 256 = 5
*/
int Fixed::toInt( void ) const
{
    return (this->m_fixed_point >> this->m_frac_bits);
}

/*  [F]
    Output stream operator
    User defined, Operator overloading.

    [ Definition ]
    Overloads the << operator to allow Fixed objects to be output to streams.
    = Fixed 객체를 스트림에 출력할 수 있도록 '<< 연산자'를 오버로딩.

    [ Logic ]
    1. Convert the Fixed object to a floating-point number using toFloat().
    = Fixed 객체를 toFloat()를 사용하여 float type로 변환

    2. Output the floating-point number to the provided output stream (out).
    = 변환된 float 숫자를 제공된 출력 스트림(out)에 출력

    3. Return the output stream to allow chaining of << operations.
    = 출력 스트림을 반환

    [ Memo ]
    used & in return value
        reason: Optimization of object copy.
            Don't need to copy for the object.
            Just get the reference instead of copy.

    used & in param
        reason: Avoid copy the object, good for efficiency.
    
    used const in param
        reason: Ensures that objects do not change.
    
    'toFloat' function doesn't change ant value of varible.
    So i put 'const' to 'toFloat'function.
*/
std::ostream& operator<<(std::ostream& out, const Fixed& m_fixed)
{
    out << m_fixed.toFloat();
    return (out);
}