#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	Fixed & operator=( Fixed const &rhs );
private:
	int					_value;
	static const int	_fractBits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif /* FIXED_HPP */
