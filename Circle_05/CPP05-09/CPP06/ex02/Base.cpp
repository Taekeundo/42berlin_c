/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:45 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:46 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* [F] Destructor for Abstract class */
Base::~Base() {}

/* [F] */
// std::cerr << "Memory allocation failed: " << e.what() << std::endl;
// generatedObject = NULL;
Base* generate()
{
    Base*   generatedObject = NULL;

    try
    {
        // Make random number.
        int randomValue = std::rand();

        // 3 Options after %: 0, 1, 2 (Each assigns to 'A', 'B', 'C').
        if (randomValue % 3 == 0)
        {
            generatedObject = new A();
            std::cout << "Generated object(A) successfully" << std::endl;   
        }
        else if (randomValue % 3 == 1)
        {
            generatedObject = new B();
            std::cout << "Generated object(B) successfully" << std::endl;
        }
        else
        {
            generatedObject = new C();
            std::cout << "Generated object(C) successfully" << std::endl;
        }
    }
    catch (const std::bad_alloc& e)
    {
        throw std::runtime_error("Memory allocation failed in generate()");
    }
    return (generatedObject);
}

/*  [F]
    [ Role ]
    Checks which child object(A,B,C)
    the parent pointer(Base *) is now pointing to.
    
    Determine the specific derived child object
    which is pointed to by the parent class (Base)
    by using dynamic_cast.

    [ Logic ]
    Paretn: Base
    Child: A, B, C
    = Convert (Parent) to (Child) // Down-casting.
*/
void identify(Base* p)
{
    A* pA = dynamic_cast<A*>(p);
    B* pB = dynamic_cast<B*>(p);
    C* pC = dynamic_cast<C*>(p);

    if (pA != NULL)
        std::cout << p << " is (A)pointer" << std::endl;
    else if (pB != NULL)
        std::cout << p << " is (B)pointer" << std::endl;
    else if (pC != NULL)
        std::cout << p << " is (C)pointer" << std::endl;
    else
        std::cout << p << "ERROR" << std::endl;
}

/* [F]
    dynamically cast pointer (p) to a reference of type <A&>
    if the cast is successful, 'ra' will be a reference to the object pointed to by 'p'

    // std::string objectTypes[] = {"A", "B", "C"};
*/
void identify(Base& p)
{
    bool ok = false;

    // Check 'A'
    try
    {
        A& refA = dynamic_cast<A&>(p);
        std::cout << &refA << " is (A)reference" << std::endl;
        ok = true;
    }
    catch(const std::exception& e) {}

    // Check 'B'
    if (ok == false)
    {
        try
        {
            B& refB = dynamic_cast<B&>(p);
            std::cout << &refB << " is (B)reference" << std::endl;
            ok = true;
        }
        catch(const std::exception& e) {}
    }

    // Check 'C'
    if (ok == false)
    {
        try
        {
            C& refC = dynamic_cast<C&>(p);
            std::cout << &refC << " is (C)reference" << std::endl;
            ok = true;
        }
        catch(const std::exception& e) {}
    }

    // Check 'Exception'
    // If any of the A, B and C types don't match, Error.
    if (ok == false)
        std::cout << "ERROR" << std::endl;
}
