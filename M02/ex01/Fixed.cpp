/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:15 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/22 12:40:45 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( Fixed const &b )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = b;
}

Fixed::Fixed( int const value )
{
	this->_value = value << Fixed::_fractBits;
}

Fixed::Fixed( float const value )
{
	this->_value = ((int)roundf(value) << Fixed::_fractBits) + (value - (int)value);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_fractBits);
}

float	Fixed::toFloat( void ) const
{
	float	result = 0;
	int	tmp = this->_value;
	std::cout << "tmp = " << tmp << std::endl;
	for (int i = Fixed::_fractBits; i > 0; i--)
	{
		result += (tmp & Fixed::_fractBits - i) * pow(2, (double)-i);
		std::cout << "i = " << i << " | tmp = " << tmp << " | tmp & 1 = " << (tmp & Fixed::_fractBits - i) << " | pow = " << (tmp & 1) * pow(2, (double)-i) << std::endl;
		tmp = tmp >> 1;
	}
	std::cout << "result = " << result << std::endl;
	return (result); 
}

Fixed & Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return (o);
}