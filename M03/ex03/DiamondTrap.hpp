#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& b);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& rhs);
	void attack(const std::string& target);
	void whoAmI();
};


#endif /* DIAMONDTRAP_HPP */
