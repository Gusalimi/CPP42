#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Viktor");
	ClapTrap b;
	ClapTrap c(a);

	a.attack("Enemy 1");
	a.takeDamage(12);
	b.takeDamage(5);
	c.beRepaired(13);
	b = a;
	b.beRepaired(5);
}
