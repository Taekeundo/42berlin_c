/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:42:39 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 15:42:40 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*  [F]
    [ Background knowledge ]
    1) STL
      = Standard Template Library
      = Library that provides easy use of
        data structures (containers) and algorithms in C++.
      = C++에서 자료구조(Containers)와 알고리즘(Algorithms)을
        쉽게 사용할 수 있도록 제공하는 라이브러리.

      (1) STL Container
        = Save and manage data
        = 데이터를 (저장)하고 관리하는 자료구조

        1. Sequence         // Store elements sequentially
          Vector
          Deque
          list
          array
      
        2. Associative      // Sorted data storage (tree-based)
          set
          map
          multiset
          multimap

        3. Adapters         // Provides only specific functions of an existing container.
          stack
          queue
          prioirty_queue

        4. Unordered        // Hash-based, fast search
          unordered_set
          unordered_map
          unordered_multiset
          unordered_multimap

      (2) STL Algorithm
        = Bunch of functions for Handling the Container, data type.
        = 컨테이너 데이터를 (다루기) 위한 표준 함수 모음

        1. Sort
          sort, stable_sort
        
        2. Search
          find, binary_search
        
        3. Numeric Operations
          accumulate

        4. Modify
          copy, transform, replace
        
        5. Remove
          remove, erase, unique

    2) Comparaision between STL Containers
    STL containers   Random Access   Middle Insert, Delete    Cache efficiency
    std::list<int>       slow                fast                   bad
    std::deque<int>      fast                slow                  normal
    std::vector<int>     fast                slow                   good

    = "std::vector" container is most efficient and commonly used.

    3) try, throw, catch
      try-block -> meet with exception: throw -> catch-block

      catch (std::exception& e) // 보통 이름을 'e' 이렇게 사용한다.

      & // Reason to use 'reference' for the exception.
      = 복사를 피하고 불필요한 포인터 처리를 피하기 위해 참조로 받는 것이 더 효율적.

    4) what() methode
      [c] std::exception can use [m] what()
      = What() gets "std::runtime_error" from the throw.

    [ Logic ]
    1. Declare 3 types of containers.
  
    2. Container Initialization
      Fill the containers with integer values from 0 to 9.
  
    3. Searching for targetValue

      try
        To use the same template function(= easyfind)
        to search the targetValue in three different types of containers.
        
    4. Exception Handling
    
      If the function does not find the targetValue in the Container,
      it throws an exception, which is caught in the [catch] block.

      The error message is printed to "std::cerr" 
      = cerr: standard error output

      이미 헤더파일에 설정된것처럼 타겟벨류를 컨테이너에서 찾지 못할 경우
      try-block에서 catch-blcok으로 "std::runtime_error"를 던진다.

      throw에서 던져진 "std::runtime_error();"는
      catch-block에서 참조(&)'e'를 통해 예외 객체로 받아 what() methode를 통해 처리된다.

      std::cerr // standard console error
*/
int main(void)
{
  // 1. Declare 3 types of containers.
  std::list<int> listContainer;
  std::deque<int> dequeContainer;
  std::vector<int> vectorContainer;

  // 2. Container Initialization
  for (int i = 0 ; i < 10 ; ++i)
  {
    listContainer.push_back(i);
    dequeContainer.push_back(i);
    vectorContainer.push_back(i);
  }

  // 3. Search in "std::list<int> listContainer"
  try
  {
    std::list<int>::iterator foundIterator = easyfind(listContainer, 6);
    std::cout << "targetValue(" << GRE << 6 << EOC << ") is on the " << GRE << "<list>" << EOC << "Container\n"
      << "  Distance:(" << GRE << std::distance(listContainer.begin(), foundIterator) << EOC << ")\n" <<std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  // 4. Search in "std::deque<int> dequeContainer"
  try
  {
    std::deque<int>::iterator foundIterator = easyfind(dequeContainer, 3);
    std::cout << "targetValue(" << GRE << 3 << EOC << ") is on the " << GRE << "<deque>" << EOC << "Container\n"
      << "  Distance:(" << GRE << std::distance(dequeContainer.begin(), foundIterator) << EOC << ")\n" <<std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  // 5. Search in "std::vector<int> vectorContainer"
  try
  {
    std::vector<int>::iterator foundIterator = easyfind(vectorContainer, 10);
    std::cout << "targetValue(" << GRE << 10 << EOC << ") is on the " << GRE << "<vector>" << EOC << "Container\n"
      << "  Distance:()" << GRE << std::distance(vectorContainer.begin(), foundIterator) << EOC << ")\n" <<std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
