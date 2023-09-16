#include <stdexcept>
#include <string>

// STEP 2

// STEP 3

class Account
{
	private:
		double balance;
	
	public:
		Account();
		Account(double initialDeposit);
		double getBalance();
		double deposit(double amount);
		double withdraw(double amount);
};