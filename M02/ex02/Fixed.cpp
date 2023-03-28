/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:15 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/14 16:04:20by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	ft_pow(int base, int exp)
{
	int	result = 1;
	for (int i = 0; i < exp; i++)
		result *= base;
	return (result);
}

const int Fixed::_fractBits = 8;
Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed( Fixed const &b )
{
	*this = b;
}

Fixed::Fixed( int const value )
{
	this->_value = value << Fixed::_fractBits;
}

Fixed::Fixed( float const value )
{
	this->_value = roundf(value * ft_pow(2, Fixed::_fractBits));
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_fractBits);
}

float	Fixed::toFloat( void ) const
{
	float result;
	result = (1.0f * (int)this->_value) / ft_pow(2, Fixed::_fractBits);
	return (result); 
}

Fixed const & Fixed::max(Fixed const & x, Fixed const & y)
{
	return (x.toFloat() > y.toFloat() ? x : y);
}

Fixed & Fixed::max(Fixed & x, Fixed & y)
{
	return (x.toFloat() > y.toFloat() ? x : y);
}

Fixed const & Fixed::min(Fixed const & x, Fixed const & y)
{
	return (x.toFloat() < y.toFloat() ? x : y);
}

Fixed & Fixed::min(Fixed & x, Fixed & y)
{
	return (x.toFloat() < y.toFloat() ? x : y);
}

Fixed & Fixed::operator=( Fixed const &rhs )
{
	this->_value = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>( Fixed const &rhs )
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<( Fixed const &rhs )
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=( Fixed const &rhs )
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=( Fixed const &rhs )
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==( Fixed const &rhs )
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=( Fixed const &rhs )
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+( Fixed const &rhs )
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-( Fixed const &rhs )
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*( Fixed const &rhs )
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const &rhs )
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++()
{
	++this->_value; 
	return (*this);
}

Fixed Fixed::operator++(int i)
{
	Fixed tmp = *this;
	(void)i;
	++(*this);
	return (tmp);
}

Fixed & Fixed::operator--()
{
	--this->_value; 
	return (*this);
}

Fixed Fixed::operator--(int i)
{
	Fixed tmp = *this;
	(void)i;
	--(*this);
	return (tmp);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return (o);
}