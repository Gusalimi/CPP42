/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:38:43 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/20 16:36:56 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}
Harl::~Harl() {}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string levelStrings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef	void	(Harl::*f)(void);
	f funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
		if (level == levelStrings[i])
			(this->*funcs[i])();
}