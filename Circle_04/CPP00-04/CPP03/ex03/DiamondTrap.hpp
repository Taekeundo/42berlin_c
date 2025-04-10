/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:20:15 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/24 14:20:16 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*  [F]
    Class 'Diamond' inherited from both 'ScavTrap' class and 'FragTrap' class.

    [ Problem ]
    class Base {
        public:
            int value;
    };

    class Derived1 : public Base {...};
    class Derived2 : public Base {...};
    class Diamond  : public Derived1, public Derived2 {...};

              Base
        /               \

    Derived1           Derived2  

        \               /
             Diamond

    = 상속받을 부모 클래스(Derived1, Derived2)가
      같은 부모(Base)를 상속받아서 구현된 경우
      이중 상속받지 않도록 가상 상속을 사용해야 함
    
    Diamond inherited 'base' two times (Two 'base' instances)
    = one is from Derived1, the other is from Derived2.
    = Not clear, that inherite from which 'base' instance.
    = conflict & confused (Computer is dumb.)
    = 다이아몬드 상속 구조에서 Diamond 클래스가 Base 클래스의 두 인스턴스를 가지게 되는 문제.

    [ Solution ]
    'virtual' inherit.
    동일 instance를 이중 상속받지 않도록 가상 상속을 사용해야 함 like below.

    class Derived1 : virtual public Base {...};
    class Derived2 : virtual public Base {...};
    class Diamond  : public Derived1, public Derived2 {...};
*/
class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string     m_name;

    public:
        DiamondTrap();                                  // Default constructor
        ~DiamondTrap();                                 // Destructor
        DiamondTrap(const DiamondTrap &rhs);            // Copy constructor
        DiamondTrap(std::string name);                  // Constructor with name param

        DiamondTrap& operator=(const DiamondTrap& rhs); // Assignment operator

        void attack(const std::string& target);         // Over-riding.
        void    whoAmi() const;
};

#endif