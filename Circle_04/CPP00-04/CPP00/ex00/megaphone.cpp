/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:39 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/21 15:41:41 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// C++ Standard Library. Under the 'std' namespace.
#include <cctype>	// toupper(), tolower(), isalnum(), isalpha()

/*	[F]
	[ Background ]
	C standard library functions such as "toupper" belong to the global namespace,
	so we don't have to use namespaces such as (std::).	
	The 'cout' function must be prefixed because it only works under the (std::)namespace.
	= toupper와 같은 C표준 라이브러리 함수들은 전역 네임스페이스에 속해 있기에
	  (std::)와 같은 네임스페이스를 사용하지 않아도 괜찮다.
	  'cout'함수는 (std::)네임스페이스 아래서만 동작하기에 꼭 prefix를 붙여줘야한다.
*/
int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				std::cout << (char)toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
