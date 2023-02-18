/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:51:53 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 12:00:28 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "Using newZombie():" << std::endl;
	Zombie	*zombie1 = newZombie("zombie1");
	zombie1->announce();
	delete zombie1;

	std::cout << "Using randomChump():" << std::endl;
	randomChump("zombie2");
}