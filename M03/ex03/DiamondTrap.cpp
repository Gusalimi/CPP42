#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "noName";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = this->FragTrap::_hp;
	this->_energy = this->ScavTrap::_energy;
	this->_damage = this->FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hp = this->FragTrap::_hp;
	this->_energy = this->ScavTrap::_energy;
	this->_damage = this->FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& b)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = b;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

void DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap::_name is " << this->ClapTrap::_name << std::endl;
}