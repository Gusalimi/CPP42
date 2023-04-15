#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "NoName";
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& b)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = b;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0)
	{
		if (this->_energy > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage !" << std::endl;
			this->_energy--;
		}
		else
			std::cout << "ClapTrap " << this->_name << " doesn't have energy left to attack !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is dead, he can't attack !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > amount)
	{
		std::cout << "ClapTrap " << this->_name << " loses " << amount << " hp !" << std::endl;
		this->_hp -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " loses " << this->_hp << " hp and dies !" << std::endl;
		this->_hp = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		std::cout << "ClapTrap " << this->_name << " gains back " << amount << " hp !" << std::endl;
		this->_hp += amount;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to be repaired !" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}
