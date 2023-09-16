#include "Account.h"


Account::Account()
{
	balance = 0;
}
		
Account::Account(double initialDeposit)
{
	balance = initialDeposit;
}
		
double Account::getBalance()
{
	return balance;
}
		
double Account::deposit(double amount)
{
	if (amount > 0)
		balance += amount;
	else
		return -1;  // STEP 4
	return balance;
}
		
double Account::withdraw(double amount)
{
	if ((amount > balance) || (amount < 0))
		return -1; // STEP 5
	else
		balance -= amount;
	return balance;
}