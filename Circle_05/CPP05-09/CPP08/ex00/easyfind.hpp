/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:42:36 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 15:42:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/* MACRO */
// Bold color definitions using ANSI
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
// Basic
#include <string>     // std::string
#include <sstream>    // std::stringstream
#include <iostream>   // std::cout, std::cerr

// Algorithm
#include <algorithm>  // std::find

// Containers
#include <list>       // std::list<int>
#include <deque>      // std::deque<int>
#include <vector>     // std::vector<int>

// Exceptional case
#include <stdexcept>  // std::runtime_error, std::exception

/** [F]
 * @brief 
 * template function
 * 
 * @param1 targetContainer 
 * Choose which type of container want to use.
 * 
 * @param2 targetValue
 * Integer type of value, want to find, among containers
 * 
 * @background
 * 1. template
 *    (Role)
 *    템플릿을 사용하면 여러 종류의 컨테이너에서 사용하는
 *    공통된 기능(ex:'find')를 일반화하여 재사용할 수 있다.
 * 
 *    (Nuts)
 *    iterator
 *    = 별도의 함수가 아니라 STL 컨테이너들이(vector, list, set, map, deque, 등)
 *      반드시 iterator 타입을 내부적으로 정의하고 제공한다.
 *    = 각각의 컨테이너들이 std::find 알고리즘을 사용해서
 *      동일한 방식으로 컨테이너의 요소들을 순차적으로 탐색하기에 템플릿으로 묶어주는거다.
 * 
 *    (ex)
 *    std::vector<int>, std::list<int>, std::deque<int>
 *    각각의 컨테이너들은 모두 std::find알고리즘을 사용해서 iterator자료구조를 취급한다.
 *    각각의 컨테이너에 대해 개별적으로 반복문을 작성하는 대신,
 *    템플릿을 사용하여 공통된 방식으로 iterator자료구조를 처리한다.
 * 
 *    (Conclusion)
 *    "std::find 알고리즘"과 "iterator라는 자료구조"를 STL 컨테이너들이 공통적으로 사용하기에
 *    템플릿으로 묶어주면 다양한 컨테이너를 효율적으로 처리할 수 있다.
 * 
 * 2. std::find
 *    특정 값이 범위 내에 있는지 확인하는 함수 from "<algorithm>" library.
 *    
 *    Param
 *      Searching range: Param(1) - Param(2)
 *      Searching target: Param(3)
 *    
 *    Return
 *      Success(value found):
 *      = iterator(similar to a pointer) pointing to the element, where 'value' is found within the range.
 * 
 *      Fail(value not found):
 *      = last iterator, which points to the end of the range.
 *        ex) std::end(*targetContainer)
 * 
 *    Exceptional case
 *      What if, 범위 내에 중복된 값이 있을 경우
 *      std::find는 첫 번째 발생한 값만 반환 & stop.
 * 
 * 3. throw std::runtime_error(...)
 * 
 *    throw
 *    = keyword, throws an exception.
 *      When meets with exceptional case, the program's flow immediately ends
 *      and goes up the call stack until the exceptional case is handled.
 * 
 * @return
 *  Type: Container::iterator
 * 
 * ex) If container's type            return
 *      std::vector<int>      ->      std::vector<int>
 *      std::deque<int>       ->      std::deque<int>
 *      std::list<int>        ->      std::list<int>
 */
template <typename Container> // Declare template, which has the name of "Container".
typename Container::iterator easyfind(Container& targetContainer, int targetValue)
{
  // Declaration of template object for handling,
  // 3 containers's data type(iterator) and algorithm(std::find).
  typename Container::iterator foundIterator = std::find(targetContainer.begin(),
                                                          targetContainer.end(),
                                                          targetValue);

  // If "std::find" function fails -> handling exceptional case by using 'throw' function.
  if (foundIterator == targetContainer.end())
  {
    std::stringstream ss;
    ss << "targetValue(" << RED << targetValue << EOC
        << ")" << RED << " isn't" << EOC << " on the Container";
    throw std::runtime_error(ss.str());
  }
  return foundIterator;
}

#endif

/*  [ Memo ]
  if (foundIterator == targetContainer.end())
  {
    std::stringstream ss;
    ss << targetValue;
    std::string stringTargetValue = ss.str();
    throw std::runtime_error("targetValue("
                              RED + stringTargetValue + EOC
                              + ") isn't on the Container"
                              + RED + "!!"+ EOC);
  }
*/
