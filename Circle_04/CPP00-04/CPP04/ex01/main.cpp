/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:43:57 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 11:43:58 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*  [F]

    [ Class hierarchy ]

                Animal
            /             \
          Dog             Cat
          /                 \
        Brain               Brain
    = getBrain()         = getBrain()
        /                      \
    setIdea()               setIdea()

    [ Memo ]
    Must use 'deep' copy, not shallow.

    [ Background ]
    Shallow copy (A = B) // Copy the address.
        When A is deleted -> B is going to be deleted automatically.
        
    Deep copy (A = B) // Copy everything.
        When A is deleted -> B doesn't take any effect.

*/
int main()
{
    std::cout << R << "[ Define instance: two animals // dog: 1, cat: 1 ]" << EOC << std::endl;
    const Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    std::cout << std::endl;

    std::cout << R << "[ Check the order when delete instance ]" << EOC << std::endl;
    delete(animals[0]);
    delete(animals[1]);
    std::cout << std::endl;

    std::cout << R << "[ Define instance: two cats ]" << EOC << std::endl;
    Cat *cat1 = new Cat();
    Cat *cat2 = new Cat();
    std::cout << std::endl;

    std::cout << R << "[ Check how does getBrain(), setIdea() work ]" << EOC << std::endl;
    std::cout << "Cat1's prev idea: " << cat1->getBrain()->getIdea(0) << std::endl;
    cat1->getBrain()->setIdea("new idea", 0);
    std::cout << "Cat1's curr idea: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    std::cout << C << "\t1. Cat2's curr idea: " << EOC << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << R << "[ Check assignment operator, 'cat2' = 'cat1' ]" << EOC << std::endl;
    *cat2 = *cat1;
    std::cout << std::endl;
    std::cout << C << "\t2. Cat2's curr idea: " << EOC << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << R << "[ De-allocate (cat1) instance ]" << EOC << std::endl;
    delete(cat1);
    std::cout << std::endl;

    std::cout << R << "[ Check shallow copy or Deep copy ]" << EOC << std::endl;
    std::cout << "Even if delete (cat1), (cat2) still alive cause it used " \
        << R << "deep" << EOC << " copy" << std::endl;
    std::cout << std::endl;
    std::cout << C << "\t3. Cat2's curr idea: " << EOC << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << R << "[ De-allocate (cat2) instance ]" << EOC << std::endl;
    delete(cat2);
    std::cout << std::endl;
    return (0);
}
