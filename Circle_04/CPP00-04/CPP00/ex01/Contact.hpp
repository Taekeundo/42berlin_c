/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:44:54 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/24 10:44:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>    // std::cout, std::endl
#include <string>      // std:string
#include <iomanip>     // std::setw
#include <cstdlib>     // std::exit
#include <cctype>      // [f] isalpha()

#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define EOC         "\033[0;0m"     // End of color

/*  [F]
    'Contact' class
*/
class Contact
{
    private:
        // Member variables: 5ea
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        // Basic: 2ea
        Contact();     // Default constructor
        ~Contact();    // Destructor

        // Getter: 3ea
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();

        // Methode: 2ea
        void        saveContact(std::string first,\
                            std::string last,\
                            std::string nick,\
                            std::string phone,\
                            std::string secret);
        void        printDetails();
};

#endif
