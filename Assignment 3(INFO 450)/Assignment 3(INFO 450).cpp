// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h> 
using namespace std;

class BankAccount
{
protected:
	int accountnumber;
	double interest;
	double balance;
public:
	BankAccount()
	{
		accountnumber = 0;
		interest = 0;
		balance = 0;
	}
	virtual void display() {};
	virtual void withdraw() {};
	virtual void deposit() {};
	virtual void orderchecks() {};
	virtual void monthlyinterest() {};
};

class Savings : public BankAccount
{


public:
	void display()
	{
		printf("ACCOUNTS SUMMARY\nSavings Account number: %d\nInterest Rate: %3.2f %\nBalance: $%3.2f\n",
			accountnumber, interest, balance);
	}
	void deposit()
	{
		double depositamt;
		cout << "Enter the account number for savings account" << endl;
		cin >> accountnumber;
		cout << "Enter amount to deposit to savings" << endl;
		cin >> depositamt;
		balance = balance + depositamt;
		cout << "Your balance is now: $" << balance << endl;
		cin.clear();
		cin.ignore();
		if (balance < 10000)
		{
			interest = .01 * 100;
			cout << "Your APR interest is: " << interest << "%" << endl;
		}
		else
		{
			interest = .02 * 100;
			cout << "Your APR interest is: " << interest << "%" << endl;
		}
	}
	void monthlyinterest()
	{
		cout << "MONTHLY INTEREST" << endl;
		double monthinterest = (balance * interest / 12) * 0.01;
		cout << "Your monthly interest for savings is: $" << monthinterest << endl;
		balance = balance + monthinterest;
	}
	void orderchecks()
	{}
	void withdraw()
	{
		double withdrawamt;
		cout << "Please enter amount to withdraw from savings " << endl;
		cin >> withdrawamt;

		cin.clear();
		cin.ignore();
		if (withdrawamt <= 0)
		{
			cout << "The amount can not be zero or negative" << endl;
		}
		else if (withdrawamt > balance)
		{
			cout << "You do not have enough balance to withdraw this amount" << endl;
		}
		else
		{
			balance = (balance - withdrawamt) - 2;
			cout << "The withdrawl is successful. Your new balance is: $" << balance << endl;
		}

		if (balance < 10000)
		{
			interest = .01 * 100;
			cout << "Your APR interest rate is: " << interest << "%" << endl;
		}
		else
		{
			interest = .02 * 100;
			cout << "Your APR interest rate is: " << interest << "%" << endl;
		}
	}
};

class checking : public BankAccount
{
	char answer[2];
public:
	void display()
	{
		printf("Checkings Account number: %d\nInterest Rate: %3.2f %\nBalance: $%3.2f\n",
			accountnumber, interest, balance);
	}
	void deposit()
	{
		double depositamt;
		cout << "Enter the account number for checking account" << endl;
		cin >> accountnumber;
		cout << "Enter amount to deposit to checking" << endl;
		cin >> depositamt;
		balance = balance + depositamt;
		cout << "Your balance is : $" << balance << endl;
		cin.clear();
		cin.ignore();
		if (balance < 500)
		{
			balance = balance - 5;
			cout << "Your balance now after fee is: $" << balance << endl;
		}
		else
		{
			cout << "";
		}
	}
	void withdraw()
	{
		double withdrawamt;
		cout << "Please enter amount to withdraw from checking " << endl;
		cin >> withdrawamt;
		cin.clear();
		cin.ignore();
		if (withdrawamt <= 0)
		{
			cout << "The amount can not be zero or negative" << endl;
		}
		else if (withdrawamt > balance)
		{
			cout << "You do not have enough balance to withdraw this amount" << endl;
		}
		else
		{
			balance = (balance - withdrawamt);
			cout << "The withdrawl is successful. Your new balance is: $" << balance << endl;
		}
	}
	void monthlyinterest()
	{}
	void orderchecks()
	{
		cout << "Would you like to order checks?" << endl;
		cout << "Press Y for yes or Press anything else to skip" << endl;
		gets_s(answer);

		if (strcmp(answer, "Y") == 0)
		{
			balance = balance - 15;
			cout << "Your order has been approved. Your checking balance is now: $" << balance << endl;
		}
		else
		{
			cout << "Continue with your operations" << endl;
		}
	}
};

class CertificateofDeposit : public BankAccount
{
	int numofterm;

public:
	void display()
	{
		printf("CertificateofDeposit Account number: %d\nInterest Rate: %3.2f %\nBalance: $%3.2f\nNumberOfTerms: %d years\n",
			accountnumber, interest, balance, numofterm);
	}
	void deposit()
	{
		cout << "Enter the account number for CD account" << endl;
		cin >> accountnumber;
		cout << "Enter amount to deposit to CD" << endl;
		cin >> balance;
		cout << "Enter number of terms for CD" << endl;
		cin >> numofterm;
		cout << "Your balance is now: $" << balance << " with a term of " << numofterm << " years" << endl;
		cin.clear();
		cin.ignore();
		if (numofterm < 5)
		{
			interest = .05 * 100;
			cout << "Your interest rate is: " << interest << "%" << endl;
		}
		else
		{
			interest = .1 * 100;
			cout << "Your interest rate is: " << interest << "%" << endl;
		}
	}
	void monthlyinterest()
	{
		double monthinterest = (balance * interest / 12) * 0.01;
		cout << "Your monthly interest for Certificate of Deposit is: $" << monthinterest << endl;
		balance = balance + monthinterest;
	}
	void orderchecks()
	{}
	void withdraw()
	{
		double withdrawamt;
		int accountterm;
		cout << "Please enter amount to withdraw from CD : " << endl;
		cin >> withdrawamt;
		cout << "Please enter current term of your account " << endl;
		cout << "Note:Extra fee charged for early withdrawal(If current term for withdraw is less than original term established for account)" << endl;
		cin >> accountterm;
		cin.clear();
		cin.ignore();
		if (withdrawamt <= 0)
		{
			cout << "Amount can not be zero or negative" << endl;
		}
		else if (withdrawamt > balance)
		{
			cout << "You do not have enough balance to withdraw this amount" << endl;
		}
		else if (accountterm < numofterm)
		{
			balance = (balance - withdrawamt) - (balance * .01);
			cout << "Early Withdrawal. Your new balance after fee is: $" << balance << endl;
		}
		else
		{
			balance = (balance - withdrawamt);
			cout << "The withdrawal was successful. Your new balance is: $" << balance << endl;
		}
	}
};

int main()
{
	int numofbanksaccounts = 3;
	BankAccount **bptr;
	char answer[3];
	int i;

	bptr = new BankAccount *[numofbanksaccounts];
	{
		cout << "Welcome" << endl;
		cout << "Please select A to begin: ";
		gets_s(answer);

		if (strcmp(answer, "A") == 0)
		{
			bptr[0] = new Savings();
			bptr[0]->deposit();
			bptr[1] = new checking();
			bptr[1]->deposit();
			bptr[2] = new CertificateofDeposit();
			bptr[2]->deposit();
			bptr[0]->display();
			bptr[1]->display();
			bptr[2]->display();
			bptr[0]->monthlyinterest();
			bptr[2]->monthlyinterest();
			bptr[0]->display();
			bptr[1]->display();
			bptr[2]->display();
			bptr[1]->orderchecks();
			bptr[1]->withdraw();
			bptr[0]->withdraw();
			bptr[2]->withdraw();
			bptr[0]->display();
			bptr[1]->display();
			bptr[2]->display();
		}
		else
		{
			cout << "Re-open" << endl;
		}
	}
	return 0;
}



