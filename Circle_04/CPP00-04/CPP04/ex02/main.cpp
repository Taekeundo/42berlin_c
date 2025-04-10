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
    [ Logic ]
    -> Animal class should not be instantiable.
    -> Shouldn't sound in Animal instance.
    -> Convert [f] makeSound to "pure" virtual function.
        Automatically Animal class is now abstract class.
    -> How to convert virtual function to "pure" virtual function?
        Add "= 0" at the end of the function declaration in parent class.
        Fix the code in 'Animal.hpp' & 'Animal.cpp'.

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
    Normal inheritance vs Virtual inheritance
        Normal inheritance: 
            1. Each child copys parent's instance everytime.
            2. The more normal inheritance, the more complexible in code.
            3. Each derived class looks at its own copy instance.
        
        Virtual inheritance:
            1. All child share one parent instance together.
            2. Save memory and avoid member duplication.
            3. Only one instance that each derived class looks at.

    Shallow copy vs Deep copy
        Shallow copy (A = B)
            Copy the address.
            When A is deleted -> B is going to be deleted automatically.
        
        Deep copy (A = B)
            Copy everything.
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

    std::cout << R << "[ Define instance: two animals // dog: 1, cat: 1 ]" << EOC << std::endl;
    const Animal* test_animals[3];
    test_animals[0] = new Dog();
    test_animals[1] = new Cat();
    // test_animals[2] = new Animal();  // Abstract class can't have their own instance.
    std::cout << std::endl;

    std::cout << R << "[ Check ex02, Animal class shouldn't sound anything ]" << EOC << std::endl;
    test_animals[0]->makeSound();
    test_animals[1]->makeSound();
    // test_animals[2]->makeSound(); // Can't use pure virtual function directly in parent class.
    std::cout << std::endl;

    std::cout << R << "[ De-allocate (test_animals[0],[1]) ]" << EOC << std::endl;
    delete(test_animals[0]);
    delete(test_animals[1]);
    std::cout << std::endl;

    return (0);
}
