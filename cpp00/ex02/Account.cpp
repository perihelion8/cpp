#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	std::cout << "index:"	<< _accountIndex  << ";";
	std::cout << "amount:"	<< _amount		  << ";";
	std::cout << "created"	<< std::endl;
}

static int	Account::getNbAccounts()	{ return _nbAccounts; }
static int	Account::getTotalAmount()	{ return _totalAmount; }
static int	Account::getNbDeposits()	{ return _totalNbDeposits; }
static int	Account::getNbWithdrawals()	{ return _totalNbWithdrawals; }

static void Account::displayAccountsInfos( void  )
{
	if (_totalAmount == 0)
		return ;
}

void Account::displayStatus( void )
{
}

static void	Account::_displayTimestamp( void )
{
	std::cout << "[" << 
}
