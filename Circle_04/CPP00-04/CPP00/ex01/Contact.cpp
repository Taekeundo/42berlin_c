/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:45:44 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/24 10:45:46 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// (1) Basic: 2ea
/*  [F]
    Constructor, Call when object is created.
    Destructor, Call when object is destroyed.
*/
Contact::Contact(){}
Contact::~Contact(){}



// (2) Getter: 3ea
/*  [F]
    [ Goal ]
    Get the variable from the 'Contact' class and return it.
*/
std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickName()
{
    return (nickName);
}



// (3) Methode: 2ea
/*  [F]
    Initialize every member variables.
    Cpy 5 argument(string type) to the member variables.
*/
void    Contact::saveContact(std::string first,\
    std::string last,\
    std::string nick,\
    std::string phone,\
    std::string secret)
{
firstName = first;
lastName = last;
nickName = nick;
phoneNumber = phone;
darkestSecret = secret;
}

/*  [F]
    [ Goal ]
    To display all the details of the selected contact.
*/
void    Contact::printDetails()
{
    std::cout << GREEN << "First name       : " << EOC << firstName << std::endl;
    std::cout << GREEN << "Last name        : " << EOC << lastName << std::endl;
    std::cout << GREEN << "Nickname         : " << EOC << nickName << std::endl;
    std::cout << GREEN << "Phone number     : " << EOC << phoneNumber << std::endl;
    std::cout << GREEN << "Darkest Secret   : " << EOC << darkestSecret << std::endl;
}
