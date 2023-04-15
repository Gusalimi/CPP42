#ifndef FragTrap_HPP
#define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& b);
	~FragTrap();
	FragTrap& operator=(const FragTrap& rhs);
	void	attack(const std::string& target);
	void	highFiveGuys();
};

#endif /* FragTrap_HPP */
