
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_name = "NoName";
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(const FragTrap& b)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = b;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called" << std::endl; }

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hp > 0)
	{
		if (this->_energy > 0)
		{
			std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage !" << std::endl;
			this->_energy--;
		}
		else
			std::cout << "FragTrap " << this->_name << " doesn't have energy left to attack !" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " is dead, he can't attack !" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << this->_name << " high five some guys !" << std::endl;
}