/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:46:05 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/24 10:46:07 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX 8

#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define EOC         "\033[0;0m"     // End of color

/*  [F]
    'Phonebook' class
*/
class Phonebook
{
    private:
        Contact contacts[MAX];      // Member in Phonebook, struct(Contact) type.
        int     contactIndex;       // Member in Phonebook, int typem.
        int     flagFull;

    public:
        // Basic: 2ea
        Phonebook();                // Constructor, Call when object is created.
        ~Phonebook();               // Destructor, Call when object is destroyed.

        // Methode: 2ea
        void    addContact();
        void    searchContact();
};

#endif
