/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:03:40 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/26 14:03:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*  [F]
    Constructor

    [ Background ]
    1. Member initialization list
    클래스의 constructor가 멤버 변수를 초기화하는 하나의 방법 (one of the ways)
    생성자 호출과 동시에 초기화된다.
    = 주로 const, &가 있을때 사용하는 방식.
    = 메모리 효율에 있어 좋은 방법이기에
      위와 같은 특별한 경우가 아니더라도 해줄 수 있으면 해주는게 좋다.
    
    [ Explanation ]
    'Weapon'함수에서 사용되는 변수를 scope안으로 들어가기전에 초기화한다.
    :m_type(type) // m_type에 type를 할당해주겠다는 의미.

    [ Why here used? ]
    성능 최적화 // 두 단계 초기화를 피할 수 있다.

    [ Other way ]
    Weapon::Weapon(std::string type){
        m_type = type;
    }
    = 동일한 기능을 한다. 단계가 하나 더 있을뿐이다.
*/
Weapon::Weapon(std::string type):m_type(type){}

/*  [F]
    Destructor // Nothing happend.
*/
Weapon::~Weapon(){}

/*  [F]
    [ Memo ]
    Return type // const std::string &
    
    Const
        Promise not to change the return value.
        객체의 상태를 변경하지 않겠다는 약속.
        getType함수에서는 Weapon 객체의 m_type 멤버를 수정할 수 없다.
        = 데이터 일관성을 유지.

    &
        Don't need to copy the value again. Directly approach.
        값 반환을 하면 새로운 메모리 공간이 할당되고 문자열 데이터가 복사.
        But &(reference)를 반환하면 기존의 메모리 공간을 재사용.
        = 메모리 효율성 상승.
    
    getType함수 내부에서 멤버 변수를 수정하지 않기에 const를 사용했고,
    이를 통해 함수가 객체의 상태를 변경하지 않음을 보장.

    객체를 복사할 필요 없이 reference를 반환하여 메모리 효율성을 높였다.
*/
const std::string &Weapon::getType()
{
    return (this->m_type);
}

/*  [F]
    함수 내부에서 멤버 변수 'm_type'이 수정되어야 하기에 const를 사용할 수 없다.
*/
void Weapon::setType(std::string type)
{
    this->m_type = type;
}
