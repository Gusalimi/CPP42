#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap a("Bob");
	ScavTrap b("Viktor");
	FragTrap c("Leon");
	DiamondTrap d("Diana");

	a.attack("Enemy 1");
	b.attack("Enemy 2");
	c.attack("Enemy 3");
	d.attack("Enemy 4");
	d.whoAmI();
}
