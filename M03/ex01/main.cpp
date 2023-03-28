#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Bob");
	ScavTrap b("Viktor");
	ScavTrap c;
	ScavTrap d(b);

	a.attack("Enemy 1");
	b.attack("Enemy 2");
	b.guardGate();
}
