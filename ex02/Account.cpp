#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>



int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(NULL);
	tm*			allTime = std::localtime(&result);

	std::cout << "[" <<  allTime->tm_year + 1900 << std::flush;
	std::cout << std::setw(2)<< std::setfill('0') << allTime->tm_mon;
	std::cout << allTime->tm_mday ;
	std::cout << "_" << allTime->tm_hour << allTime->tm_min << allTime->tm_sec  << "] "<< std::flush;

}

int		Account::checkAmount( void ) const
{
	return (_amount);
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" <<	getTotalAmount() << ";deposits:" << getNbDeposits() <<";withdrawals:" << getNbWithdrawals() << std::endl;
}



Account::Account( int initial_deposit )
	:	_accountIndex(_nbAccounts++),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount <<";created" << std::endl;;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout <<"amount:" << _amount << ";";
	std::cout <<"deposits:" << _nbDeposits << ";";
	std::cout <<"withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_totalAmount += deposit;
    _totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";

	if (withdrawal > checkAmount())
	{        
		std::cout << "refused" << std::endl;
        return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";closed" << std::endl ;

}



