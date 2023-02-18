/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:51:53 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 13:05:31 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	std::cout << "N = 12:" << std::endl;
	Zombie	*horde = zombieHorde(12, "Mike");
	for (int i = 0; i < 12; i++)
	{
		std::cout << "horde[" << i << "].announce():" << std::endl;
		horde[i].announce();
	}
	delete [] horde;

	std::cout << std::endl << "N = 30:" << std::endl;
	horde = zombieHorde(30, "Timmy");
	for (int i = 0; i < 30; i++)
	{
		std::cout << "horde[" << i << "].announce():" << std::endl;
		horde[i].announce();
	}
	delete [] horde;

	std::cout << std::endl << "N = 2:" << std::endl;
	horde = zombieHorde(2, "Bob");
	for (int i = 0; i < 2; i++)
	{
		std::cout << "horde[" << i << "].announce():" << std::endl;
		horde[i].announce();
	}
	delete [] horde;
}