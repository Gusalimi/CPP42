// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Mon Feb 13 18:48:15 2023                      //
//                Last update : Tue Feb 14 14:54:06 2023                      //
//                Made by : Guillaume Sailé <gsaile@student.42mulhouse.fr>    //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t	t = std::time(0);
	std::tm		*now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900;
	if (now->tm_mon < 10)
		std::cout << "0";
	std::cout << now->tm_mon;
	if (now->tm_mday < 10)
		std::cout << "0";
	std::cout << now->tm_mday << "_";
	if (now->tm_hour < 10)
		std::cout << "0";
	std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0";
	std::cout << now->tm_min;
	if (now->tm_sec < 10)
		std::cout << "0";
	std::cout << now->tm_sec << "]";
}

int	Account::getNbAccounts( void ) { return (Account::_nbAccounts); }

int	Account::getTotalAmount( void ) { return (Account::_totalAmount); }

int	Account::getNbDeposits( void ) { return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (Account::_totalNbWithdrawals); }

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout <<  " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}
Account::~Account( void )
{
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void ) const { return (this->_amount); }
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

