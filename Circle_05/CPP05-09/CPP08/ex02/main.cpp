/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:43:54 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/18 15:43:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*  [ Memo ]
    [ Basic ]
    1. Template
        A mechanism for creating generic classes or functions.

    2. Container
        A class template or a data structure,
        that can store and organize multiple elements of the same or different types.

    [ Project's goal for learning ]
    1. Problem
        std::stack is stack one by one. Donsn't have any iterator.
        Inefficient to print the middle element. (맨 위에서만 push(), pop(), top())
        = 중간에 있는 원소를 출력하려면, 하나씩 pop() 하면서 확인해야 하므로 매우 비효율적.

    2. Solving
        By leveraging the internal container(= std::deque<T>)) of std::stack,
        we could use 'iterator', making it possible to efficiently traverse and access middle elements, including those in the middle.
        = Overcomes the limitations of std::stack by introducing iterator support.

    = "std::stack"처럼 직접 iterotor를 제공하지 않는 container adapter도
      하위 컨테이너의 이터레이터를 활용해서 iterotor기능을 추가할 수 있다는 점을 학습.

    [ Background knowledge ]
    1. std::stack<T>의 내부 구조 이해

        [ Definition ]
        1. LIFO방식으로 작동하고
        2. 내부 컨테이너(std::deque<T> || std::vector<T>)를 활용해 요소를 저장하는 Container Adapter다.
        
        [ Form ]
        template <class T, class Container = std::deque<T>> // 기본 컨테이너 std::deque<T>
        class stack
        {
            protected:
                Container c;  // 데이터를 저장하는 컨테이너 (보통 std::deque<T>)
            public:
                void push(const T& val) { c.push_back(val); }   // 내부 컨테이너에 데이터 추가
                void pop() { c.pop_back(); }                    // 내부 컨테이너에서 데이터 제거
                T& top() { return c.back(); }                   // 마지막 element 참조
                bool empty() const { return c.empty(); }        // 스택이 비어 있으면 true, 그렇지 않으면 false를 반환
                size_t size() const { return c.size(); }        // 스택에 저장된 요소 개수 반환
                stack& operator=(const stack& other)
                {
                    c = other.c; // 내부 컨테이너의 복사 대입 연산자 호출
                    return *this;
                }
        };

        [ Property ]
        1. Save data basically in container_type(std::deque<T>).
            std::stack자체가 데이터를 직접 저장하는 게 아니라,
            내부 컨테이너(보통 std::deque<T>)를 이용해 데이터를 저장 & 관리한다.

        2. std::stack<T> itself doesn't have iterator(begin(), end()).
            std::stack<T> 자체에는 반복자(= Iterator: ex) begin(), end())가 없다.
            = 자체로는 원소를 순회(iterate)할 수 없다.
            = std::stack이 사용하는 내부 컨테이너(std::deque<T>)에는 반복자가 존재한다.
            = iterator, const_iterator, reverse_iterator, const_reverse_iterator

            (ex)
            int main(void)
            {
                std::stack<int> s;
                s.push(10);
                s.push(20);
                s.push(30);

                while (!s.empty())
                {
                    std::cout << s.top() << std::endl;
                    s.pop();
                }
                return (0);
            }
            = 출력 가능 BUT!! pop()호출 -> 스택의 가장 위 요소 제거 -> 재사용 불가
    
    2. std::deque<T>, std::vector<T>에서 제공하는 begin, end함수
        begin()
        end()
        rbegin()
        rend()
        -------------------- Below 4 functions only allow in C++ 11 version
        cbegin()
        cend()
        crbegin()
        crend()
*/

/*
    17  -> top() // print(1): 17  -> pop();
    = delete, not exist anymore.

    0   -> push() 5th   // mstack.end() = ite
    737 -> push() 4th
    5   -> push() 3rd
    3   -> push() 2nd
    5   -> push() 1st   // mstack.begin() = it

    std::cout << *it << std::endl;
    = Print from begin to end.
    = 5 3 5 737 0
*/
void testBasicIterator()
{
    MutantStack<int>    mstack;

    mstack.push(5);     // mstack.begin() = it // "bottom of stack"
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);     // mstack.end() = ite

    std::cout << RED << "(Print stack from 'top' to 'bottom')" << EOC << std::endl;
    MutantStack<int>    copystack(mstack);
    while (!copystack.empty())
    {
        std::cout << copystack.top() << "\t";
        copystack.pop();
    }
    std::cout << std::endl;

    // The position of begin() in stack, is at the bottom of the stack.
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    // Test for 'it' works like pointer.
    // it starts from begin -> begin + 1 -> begin + 1 - 1 -> final: begin.
    ++it;
    --it;

    std::cout << RED << "(Print iterator from the begin)" << EOC << std::endl;
    while (it != ite)
    {
        std::cout << *it << "\t";
        it++;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
}

void    testConstIterator()
{
    MutantStack<char>   mstack;

    mstack.push('j');       // mstack.begin() = cit // "bottom of stack"
    mstack.push('a');
    mstack.push('s');
    mstack.push('o');
    mstack.push('n');       // mstack.end() = cite

    std::cout << RED << "(Print stack from 'top' to 'bottom')" << EOC << std::endl;
    MutantStack<char>    copystack(mstack);
    while (!copystack.empty())
    {
        std::cout << copystack.top() << "\t";
        copystack.pop();
    }
    std::cout << std::endl;

    MutantStack<char>::const_iterator cit = mstack.cbegin();
    MutantStack<char>::const_iterator cite = mstack.cend();

    ++cit;
    --cit;

    std::cout << RED << "(Print iterator from the begin)" << EOC << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << "\t";
        cit++;
    }
    std::cout << std::endl;
}

void testReverseIterator()
{
    MutantStack<float> mstack;

    mstack.push(1.1);       // "bottom of stack"
    mstack.push(3.1);
    mstack.push(8.15);
    mstack.push(10.9);
    mstack.push(12.25);

    std::cout << RED << "(Print stack from 'top' to 'bottom')" << EOC << std::endl;
    MutantStack<float>    copystack(mstack);
    while (!copystack.empty())
    {
        std::cout << copystack.top() << "\t";
        copystack.pop();
    }
    std::cout << std::endl;

    /*
        Original:
            mstack.begin() = rit    // 1.1
            mstack.end() = rite     // 12.25
        
        reverse_iterator:
            mstack.begin() = rit    // 12.25
            mstack.end() = rite     // 1.1
    */
    MutantStack<float>::reverse_iterator rit = mstack.rbegin();
    MutantStack<float>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;

    std::cout << RED << "(Print iterator from the begin)" << EOC << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << "\t";
        rit++;
    }
    std::cout << std::endl;
}

void testConstReverseIterator()
{
    MutantStack<std::string>    mstack;

    mstack.push("guys");            // "bottom of stack"
    mstack.push("meet you");
    mstack.push("nice to");
    mstack.push("is jason");
    mstack.push("My name");

    std::cout << RED << "(Print stack from 'top' to 'bottom')" << EOC << std::endl;
    MutantStack<std::string>    copystack(mstack);
    while (!copystack.empty())
    {
        std::cout << copystack.top() << std::endl;
        copystack.pop();
    }

    /*
        Original:
            mstack.begin() = crit    // guys
            mstack.end() = crite     // My name

        reverse_iterator:
            mstack.begin() = crit    // My name
            mstack.end() = crite     // guys
    */
    MutantStack<std::string>::const_reverse_iterator crit = mstack.crbegin();
    MutantStack<std::string>::const_reverse_iterator crite = mstack.crend();

    ++crit;
    --crit;

    std::cout << RED << "(Print iterator from the begin)" << EOC << std::endl;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        crit++;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << GRE << "[ 1. testBasicIterator ]"<< EOC << std::endl;
    testBasicIterator();
    std::cout << std::endl << std::endl << std::endl;

    std::cout << GRE << "[ 2. testConstIterator ]"<< EOC << std::endl;
    testConstIterator();
    std::cout << std::endl << std::endl << std::endl;

    std::cout << GRE << "[ 3. testReverseIterator ]"<< EOC << std::endl;
    testReverseIterator();
    std::cout << std::endl << std::endl << std::endl;

    std::cout << GRE << "[ 4. testConstReverseIterator ]"<< EOC << std::endl;
    testConstReverseIterator();

    return (0);
}
