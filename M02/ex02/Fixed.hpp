#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

int	ft_pow(int base, int exp);

class Fixed
{
public:
	Fixed();
	Fixed( Fixed const &b );
	Fixed( int const value );
	Fixed( float const value );
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static	Fixed const & max(Fixed const & x, Fixed const & y);
	static	Fixed & max(Fixed & x, Fixed & y);
	static	Fixed const & min(Fixed const & x, Fixed const & y);
	static	Fixed & min(Fixed & x, Fixed & y);
	Fixed & operator=( Fixed const &rhs );
	bool operator>( Fixed const &rhs );
	bool operator<( Fixed const &rhs );
	bool operator>=( Fixed const &rhs );
	bool operator<=( Fixed const &rhs );
	bool operator==( Fixed const &rhs );
	bool operator!=( Fixed const &rhs );
	Fixed operator+( Fixed const &rhs );
	Fixed operator-( Fixed const &rhs );
	Fixed operator*( Fixed const &rhs );
	Fixed operator/( Fixed const &rhs );
	Fixed & operator++();
	Fixed operator++(int);
	Fixed & operator--();
	Fixed operator--(int);
private:
	int					_value;
	static const int	_fractBits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif /* FIXED_HPP */
