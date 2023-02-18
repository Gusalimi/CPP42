/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:41:03 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 13:45:02 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ): type(type) {};
Weapon::Weapon( void ) {}
Weapon::~Weapon() {}
const std::string	&Weapon::getType( void ) const
{
	return (this->type);
}
void		Weapon::setType(std::string newType) {	this->type = newType; }