/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:44 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/24 10:43:46 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*	[F]
	[ Logic ]
	1. Read the user_input and save it to 'cmd'.
	2. Check if 'eof: end of file' is reached // 'ctrl + d' during execution.
	3. If find strings (ADD, SEARCH, EXIT), call the suitable function.
	4. To clear the error flags on the std::cin stream.	// Error handling.
	5. To ignore remaining characters in the input buffer. // Buffer Cleaning.

	[ Background ]
	'cin'
	= different working process with (char vs int).
		char: save to buffer.
		num: Don't need to use buffer.
*/
int main(int ac, char **av)
{
	std::string	cmd;		// Under the umbrella.
	Phonebook	phonebook;

	while (1)
	{
		std::cout << "Type the command [ "
			<< GREEN << "ADD" << EOC << " | "
			<< YELLOW << "SEARCH" << EOC << " | "
			<< RED << "EXIT" << EOC << " ]: ";
		getline(std::cin, cmd);				// 1.
		if (std::cin.eof())					// 2.
		{
			std::cin.clear();				// clear the EOF flag.
			std::cin.ignore(4096, '\n');	// ignore remaining charactres until newline.
			break ;							// exit the loop.
		}
		if (!cmd.compare("ADD"))			// 3.
			phonebook.addContact();
		else if (!cmd.compare("SEARCH"))
			phonebook.searchContact();
		else if (!cmd.compare("EXIT"))
			break ;
		else
			std::cout << RED << "Invalid command" << EOC << std::endl;
	}
	return (0);
}

/*	[ RULE ]
	Forbidden
	C++ 11
		1. printf
		2. alloc
		3. free

	PhoneBook
	1. Array of contacts.
	2. MAX: 8 contacts.
	3. Over 8 contact -> ex) 9 contact -> replace the oldest one.

	Function of phonebook
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

	3. EXIT
		Program quits and delete every data.

	4. ETC
		Program stops only accept the command 'EXIT'.
*/