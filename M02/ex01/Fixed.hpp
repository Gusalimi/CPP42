#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed( Fixed &b );
	Fixed( int const value );
	Fixed( float const value );
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	Fixed & operator=( Fixed const &rhs );
private:
	int					_value;
	static const int	_fractBits;
};

#endif /* FIXED_HPP */
