#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap a("Bob");
	ScavTrap b("Viktor");
	FragTrap c("Leon");

	a.attack("Enemy 1");
	b.attack("Enemy 2");
	c.attack("Enemy 3");
	c.highFiveGuys();
}
