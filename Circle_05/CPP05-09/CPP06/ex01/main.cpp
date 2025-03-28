/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:10 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:10 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data	original = {42, "Hello, Serializer!"};
	Data*	pOriginal = &original;

	// 1. Print the original's address.
	std::cout << GRE << "[ 1. Check the original's address ]" << EOC << std::endl;
	std::cout << "Pointer(= pOriginal) points to: "
				<< YEL << pOriginal << EOC
				<< std::endl << std::endl;

	// 2. Print the current 'pOriginal' value and text.				
	std::cout << GRE << "[ 2. Print the pOriginal's status ]" << EOC << std::endl;
	std::cout << "pOriginal points to the value("
				<< PUR << pOriginal->value << EOC
				<< ") and the text ("
				<< PUR << pOriginal->text << EOC
				<< ")." << std::endl << std::endl;
	
	// 3. Serialize
	// Convert a pointer(=pOriginal) into an (uintptr_t)type.
	std::cout << GRE << "[ 3. Serialize pOriginal ]" << EOC << std::endl;
	uintptr_t	serializedResult = Serializer::serialize(pOriginal);
	std::cout << "[Hex] Serialized result: "
				<< PUR << std::hex << serializedResult << EOC << std::endl;
	std::cout << "[Decimal] Serialized result: "
				<< PUR << std::dec << serializedResult << EOC << std::endl << std::endl;

	// 4. Deserialize
	// Convert 'serializedResult' back to a pointer.
	std::cout << GRE << "[ 4. Deserialize serializedResult ]" << EOC << std::endl;
	Data*	deserialized = Serializer::deserialize(serializedResult);
	std::cout << "Pointer(= deserialized) points to: "
				<< YEL << deserialized << EOC
				<< std::endl << std::endl;

	// 5. Check, whether the original data is same as deserializedResult
	std::cout << GRE << "[ 5. Compare deserialize & pOriginal ]" << EOC << std::endl;
	if (deserialized == pOriginal)
		std::cout << YEL << "Success: Deserialization returned the original pointer" << std::endl;
	else
		std::cout << RED << "Fail: Deserialized pointer isn't same with the original pointer" << std::endl;

	std::cout << std::endl;
}
