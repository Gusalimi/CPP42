// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Mon Feb 13 18:48:15 2023                      //
//                Last update : Tue Feb 14 14:54:06 2023                      //
//                Made by : Guillaume Sailé <gsaile@student.42mulhouse.fr>    //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return (0);
}

int	Account::getTotalAmount( void )
{
	return (0);
}

int	Account::getNbDeposits( void )
{
	return (0);
}

int	Account::getNbWithdrawals( void )
{
	return (0);
}

void Account::displayAccountsInfos( void )
{
}

Account::Account( int initial_deposit ) { (void)initial_deposit; }
Account::~Account( void ) {}

void	Account::makeDeposit( int deposit ) {(void)deposit;}
bool	Account::makeWithdrawal( int withdrawal ) {return withdrawal; }
int		Account::checkAmount( void ) const {return (0);}
void	Account::displayStatus( void ) const {}

void	_displayTimestamp( void ) {}

