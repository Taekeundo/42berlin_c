/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:53 by tkwak             #+#    #+#             */
/*   Updated: 2025/03/28 15:01:53 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*	[F]
	[ Background ]
	1. [f] std::rand()
		Seed value를 기준으로 난수를 생성한다.
		Seed value가 동일하면 항상 같은 난수를 반환한다.
		이를 방지하기 위해 seed값을 다르게 설정해야 한다.
		그때 필요한게 std::srand()함수다.

	2. [f] std::srand(std::time(0))
		-> std::srand() // Specify the seed value.
		-> std::time(0) // 현재 시간을 초 단위로 반환한다.
		= 현재 시간을 기반으로 seed값을 설정한다.

		std::srand()를 통해 설정된 seed값은 프로그램 실행 동안 계속 유지된다.
*/
int	main()
{
	std::srand(std::time(0));		// 0. Make seed value following by the current time.

	try
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << GRE << "[ Test: " << i << " ]" << EOC << std::endl;
			Base* base = generate();	// 1. Down-casting, (Parent: Base) points to (Child: A or B or C).
			if (base == NULL)
			{
				std::cerr << "Error: Failed to generate object" << std::endl;
				continue;
			}
			std::cout << BLU << "[  Pointer  ] " << EOC;
			identify(base);				// 2. Child with Pointer type
			std::cout << YEL << "[ Reference ] " << EOC;
			identify(*base);			// 3. Child with Reference type
			std::cout << std::endl;		// 4. Print '\n'
			delete (base);				// 5. In [f]identify, using new.
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
