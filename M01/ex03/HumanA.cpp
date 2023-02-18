/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:48:50 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 14:45:36 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
}