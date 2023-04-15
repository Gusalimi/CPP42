#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& b);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& rhs);
	void	attack(const std::string& target);
	void	guardGate();
};

#endif /* SCAVTRAP_HPP */
