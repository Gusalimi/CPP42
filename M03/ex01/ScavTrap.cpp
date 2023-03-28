
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_name = "NoName";
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& b)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = b;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; }

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp > 0)
	{
		if (this->_energy > 0)
		{
			std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage !" << std::endl;
			this->_energy--;
		}
		else
			std::cout << "ScavTrap " << this->_name << " doesn't have energy left to attack !" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is dead, he can't attack !" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " entered Gate Keeper mode !" << std::endl;
}