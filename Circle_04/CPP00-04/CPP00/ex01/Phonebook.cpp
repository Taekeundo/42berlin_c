/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:45:59 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/24 10:46:02 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*  [F]
    [ Definition ]
    Constructor, Call when object is created.

    [ Role ]
    Initialize (m_contact_index) to 0.
*/
Phonebook::Phonebook(){
    contactIndex = 0;
}

/*  [F]
    [ Definition ]
    Destructor, Call when object is destroyed.
*/
Phonebook::~Phonebook(){}

/*  [F]
    [ Role ]
    1. Read(get) one line from "user_input"(stdin) and Save it to the '&data'.
    2. Checks for the end-of-file (EOF) condition.
        YES: EOF is detected // when there is no more input to read
            -> print a newline      // std::cout << std:endl;
            -> Terminate program    // std::exit(0)
*/
void    getData(std::string &data)
{
    std::getline(std::cin, data);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        std::exit(0);
    }
}

/*  [F]
    [ Role ]
    Display(print) a table of contacts with formatted columns.
	
    [ Mendatory ]
	a. 4 columns
		index | first name | last name | nick name

	b. Each column must be "10 characters wide"
		(ex) |          | // 10 empty spaces

	c. Text must be right-aligned.
		(ex) |     jason|

	d. Over 10 characters
		must be truncated.
		last displayable character must be replaced by a dot ('.').

	e. Index wrong
		Show error message: "Invalid index".
		Show again for the index of the entry to display.

	f. Everything is fine, show

    [ Detail ]
    1. Loop for each contact.

    2. Index Column, set width (10)

    3. First Name Column, set width (10)
        Check the length of the 'first name'
             If -> the length is over 10 characters.
                -> Must truncated it to fit within the table.
                -> substr(0, 9) // (index, length)
                   truncate starting from the index'0' and 9 letter.
                -> print '.' to 10 digit and '|' to 11 digit.
             else -> print 'first name' & '|'

    4. Last Name Column, set width (10)
        Same logic as 'first name column'.

    5. Nick Name Column, set width (10)
        Same logic as 'first name column'.
*/
void    showAllContact(Contact contacts[MAX])
{
    std::cout << std::endl;
    std::cout << GREEN << "--------------------------------------------" << EOC << std::endl;
    std::cout << "     index|first name| last name| nick name|" << std::endl;
    std::cout << GREEN << "--------------------------------------------" << EOC << std::endl;

    for (int i = 0; i < MAX; i++)                                               // 1.
    {
        std::cout << GREEN << std::setw(10) << std::right << i << EOC << "|";   // 2.
        if (contacts[i].getFirstName().length() > 10)                           // 3.
            std::cout << contacts[i].getFirstName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
        if (contacts[i].getLastName().length() > 10)                            // 4.
            std::cout << contacts[i].getLastName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getLastName() << "|";
        if (contacts[i].getNickName().length() > 10)                            // 5.
            std::cout << contacts[i].getNickName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getNickName() << "|";
        std::cout << std::endl;
    }
}

/*  [F]
    [ public ]

    [ Mandatory ]
	1. ADD
		Role: save new contact
		Detail:
			a. They are prompted to input the information of the new contact at a time.
			b. All fileds have benn completed, add the contact to the phonebook.
			c. fields
			 - first name
			 - last name
			 - nick name
			 - phone number
			 - darkest secret

    [ Role ]
    Store 'user_input' into the Contact class.

    [ Detail ]
    1. store all info of current contact in m_contacts[m_contact_index] within the array.
       
    2. Go to the next contact_index (= m_contact_index + 1)
        ex) m_contact_index: 8 -> 9 % 1 = 1
*/
void Phonebook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    while (1)
    {
        std::cout << "1. First name     : ";
        getData(firstName);
        if (!isalpha(firstName[0]))
        {
            std::cout << RED << "ERROR: Name must start with an alphabet" << EOC << std::endl;
            continue;
        }
        if (firstName[0])
            break;
    }

    while (1)
    {
        std::cout << "2. Last name      : ";
        getData(lastName);
        if (!isalpha(lastName[0]))
        {
            std::cout << RED << "ERROR: Name must start with an alphabet" << EOC << std::endl;
            continue;
        }
        if (lastName[0])
            break;
    }

    while (1)
    {
        std::cout << "3. Nickname       : ";
        getData(nickName);
        if (!isalpha(nickName[0]))
        {
            std::cout << RED << "ERROR: Name must start with an alphabet" << EOC << std::endl;
            continue;
        }
        if (nickName[0])
            break;
    }

    while (1)
    {
        std::cout << "4. Phone Number   : ";
        getData(phoneNumber);
        if (!isdigit(phoneNumber[0]))
        {
            std::cout << RED << "ERROR: Number must start with a digit" << EOC << std::endl;
            continue;
        }
        if (phoneNumber[0])
            break;
    }

    while (1)
    {
        std::cout << "5. Darkest Secret : ";
        getData(darkestSecret);
        if (!darkestSecret[0])
            std::cout << RED << "ERROR: Type something not enter" << EOC << std::endl;
        else
        {
            if (darkestSecret[0] == 32)
                std::cout << RED << "ERROR: Type something not space" << EOC << std::endl;
            else
                break;
        }
    }
    contacts[contactIndex].saveContact(firstName,
                                            lastName, nickName,
                                            phoneNumber, darkestSecret);    // 1.
    if (contactIndex >= 0 && contactIndex < 7)
        contactIndex = (contactIndex + 1) % MAX;                      // 2.
    else
    {
        contactIndex = (contactIndex + 1) % MAX;
        flagFull = 1;
    }
    std::cout << "current index: " << RED << contactIndex << EOC << std::endl;
}

/*  [F]
    [ Mandatory ]
	2. SEARCH
		Role: display contacts
		Detail:
			a. 4 columns
				index | first name | last name | nick name

			b. Each column must be "10 characters wide"
				(ex) |          | // 10 empty spaces

			c. Text must be right-aligned.
				(ex) |     jason|

			d. Over 10 characters
				must be truncated.
				last displayable character must be replaced by a dot ('.').

			e. Index wrong
				Show error message: "Invalid index".
				Show again for the index of the entry to display.

			f. Everything is fine, show

    [Detail]
    1. Index is typing number while program is running.
    2. Can't search anything, cause nothing is now stored.
    3. Show all contacts until now be saved.
    4. Save 'user_input' to 'index'.
    5. Check m_contacts[index]'s "first name".
        5-1. if it's empty -> print "Invalid index".
        5-2. else -> print details (call [f] printDetails()).
*/
void Phonebook::searchContact()
{
    std::string index;              // 1.

    if (contactIndex == 0)          // 2.
    {
        if (flagFull != 1)
        {
            std::cout << RED << "Phone Book is Empty" << EOC << GREEN << "ADD first" << EOC << std::endl;
            return;
        }
        else
            std::cout << RED << "Phone Book is FULL" << EOC << std::endl;
    }
    showAllContact(contacts);     // 3.
    std::cout << std::endl;
    while (1)
    {
        std::cout << "Tpye index " << RED << "[0-7]" << EOC << " to see more detail: ";
        getData(index);            // 4.
        if (index.length() == 1 && '0' <= index[0] && index[0] <= '7')
        {
            if (contacts[index[0] - '0'].getFirstName().empty())  // 5-1.
            {
                std::cout << RED << "Empty in this index" << EOC << std::endl;
                continue;
            }
            else                                                    // 5-2.
            {
                std::cout << std::endl;
                contacts[index[0] - '0'].printDetails();
                std::cout << std::endl;
                break;
            }
        }
        else
            std::cout << RED << "Invalid index: " << EOC << "Index must be " << GREEN << "[0-7]" << EOC << std::endl;
    }
}
