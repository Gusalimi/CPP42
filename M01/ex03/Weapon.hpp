#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon( std::string type );
	Weapon( void );
	~Weapon();
	const std::string	&getType( void ) const;
	void		setType(std::string newType);
private:
	std::string	type;
};

#endif
