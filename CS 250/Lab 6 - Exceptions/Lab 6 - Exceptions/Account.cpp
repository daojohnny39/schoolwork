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

	// STEP 4 - DONE
	else
		throw NegativeAmount("Error, you can't deposit a negative amount!");

	return balance;
}
		
double Account::withdraw(double amount)
{
	if (amount > balance)
		// STEP 5 - DONE
		throw InsufficientFunds("Error, account has insufficient funds for withdrawl!");
	else if (amount < 0)
		throw NegativeAmount("Error, you can't withdraw a negative amount!");
	else
		balance -= amount;
	return balance;
}