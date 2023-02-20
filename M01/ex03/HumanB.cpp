/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:48:50 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/20 13:24:19 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::attack( void )
{
	if (this->_weapon)
		std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}