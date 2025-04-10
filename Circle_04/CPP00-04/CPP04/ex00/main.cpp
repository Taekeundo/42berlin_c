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
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*  [F]
    [ What i learned ]
    1. Virtual function
    2. Polymorphism
    3. Dynamic binding

    !!Must study more!!
    동적바인딩, 정적바인딩
*/
int main()
{
    std::cout << R << "[ Define instance & allocate memory ]" << EOC << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;

    std::cout << R << "[ Check type ]" << EOC << std::endl;
    std::cout << "animal instance's type: " << B << animal->getType() << EOC << std::endl;
    std::cout << "dog instance's type: " << G << dog->getType() << EOC << std::endl;
    std::cout << "cat instance's type: " << Y << cat->getType() << EOC << std::endl;
    std::cout << std::endl;

    std::cout << R << "[ Check sound ]" << EOC << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    std::cout << R << "[ Define wrong instance & allocate memory ]" << EOC << std::endl;
    const WrongAnimal* animal2 = new WrongAnimal();
    const WrongAnimal* cat2 = new WrongCat();
    std::cout << std::endl;

    std::cout << R << "[ Check type ]" << EOC << std::endl;
    std::cout << "WrongAnimal instance's type: " << B << animal2->getType() << EOC << std::endl;
    std::cout << "WrongCat instance's type: " << Y << cat2->getType() << EOC << std::endl;
    std::cout << std::endl;

    std::cout << R << "[ Check sound ]" << EOC << std::endl;
    animal2->makeSound();
    cat2->makeSound();
    std::cout << std::endl;

    std::cout << R << "[ De-allocate every instance ]" << EOC << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete animal2;
    delete cat2;

    return (0);
}
