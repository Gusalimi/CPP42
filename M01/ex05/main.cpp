/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:52:09 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/20 16:26:01 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl harl;
	std::cout << std::endl << "Complain with DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Complain with INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Complain with WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Complain with ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "Complain with something else:" << std::endl;
	harl.complain("OFD");
	std::cout << std::endl;
}