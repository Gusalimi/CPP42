/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:52:09 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/20 16:36:45 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	int		minLevel = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (argc != 2)
		minLevel = 0;
	else
		for (int i = 0; i < 4; i++)
			if (argv[1] == levels[i])
				minLevel = i;
	switch(minLevel)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}