/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:32 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:32 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* [ OCCF ]: 4ea */
// 1. Default constructor
Serializer::Serializer() {}

// 2. Destructor
Serializer::~Serializer() {}

// 3. Copy constructor
Serializer::Serializer(const Serializer& other)
{
    static_cast<void>(other);
}

// 4. Overloaded assignment operator
Serializer &Serializer::operator=(const Serializer& rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

// ---------------------------------------------------------------------- //

/* [ Methods ]: 2ea */
/*  [F]
    [ Role ]
    Convert (Data* ptr)type to (uintptr_t)type and return it.
    = 포인터(주소)타입을 정수형 값으로 변환시키고 반환한다.
    = 주소를 일반적인 데이터 형식으로 처리 할 수 있다.

    [ Backgroud ]
    Why <uintptr_t> type?
    = 메모리 주소를 손실 없이 정확하고 안전하게 저장 할 수 있는 데이터 타입.
    = 정수 타입 중 하나로, 포인터 주소를 정수 형식으로 안전하게 변환하고
      다시 포인터로 복원할 수 있는 타입이기에 직렬화 및 역직렬화 과정에서 사용된다.
*/
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/*  [F]
    [ Role ]
    Convert (uintptr_t)type back to (Data* ptr)type.
    = Reverse version of the [f]serialization.
*/
Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
