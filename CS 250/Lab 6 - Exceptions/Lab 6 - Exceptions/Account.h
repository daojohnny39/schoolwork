#include <stdexcept>
#include <string>

// STEP 2 - DONE
class NegativeAmount : public std::logic_error
{
public:
	NegativeAmount(std::string errorMessage) : std::logic_error(errorMessage) {};
};

// STEP 3 - DONE
class InsufficientFunds : public std::logic_error
{
public:
	InsufficientFunds(std::string errorMessage) : std::logic_error(errorMessage) {};
};

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