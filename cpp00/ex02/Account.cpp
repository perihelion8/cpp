#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex  << ';';
	std::cout << "amount:"	<< _amount		  << ';';
	std::cout << "created"	<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex  << ';';
	std::cout << "amount:"	<< _amount		  << ';';
	std::cout << "closed"	<< std::endl;
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbDeposits; }

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *t = std::localtime(&now);

    std::cout
        << '['
        << (t->tm_year + 1900)
        << std::setw(2) << std::setfill('0') << (t->tm_mon + 1)
        << std::setw(2) << std::setfill('0') << t->tm_mday
        << '_'
        << std::setw(2) << std::setfill('0') << t->tm_hour
        << std::setw(2) << std::setfill('0') << t->tm_min
        << std::setw(2) << std::setfill('0') << t->tm_sec
        << "] ";
}

void Account::displayAccountsInfos(void)
{
	if (_totalAmount == 0)
		return ;

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';

	if (withdrawal >= _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
