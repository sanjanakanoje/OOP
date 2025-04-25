#include<iostream>
#include<string>
using namespace std;
class Bank{
	public:
		void deposit(int amount)
		{
			cout<<"Depositing Rupees "<<amount<<" in cash"<<endl;
		}
		
		void deposit(double amount)
		{
			cout<<"Depositing Rupees "<<amount<<" via digital payment"<<endl;
		}
		void deposit(string UPIID,double amount)
		{
			cout<<"Depositing Rupees "<<amount<<" Using UPI"<<endl;
		}
		
};

class Account{
	private:
		int accountNumber;
		double balance;
		
	public:
		Account(int accNum,int bal)
		{
			accountNumber = accNum;
			balance = bal;
		}
		void displayDetails()
		{
			cout<<"Account "<<accountNumber<<" Balance :Rupees "<<balance<<endl;

		}
		
		Account operator +(Account&other)
		{
			Account NewAccount(accountNumber,balance + other.balance);
			cout<<"Transfering rupees "<<other.balance<<" from Account"<<other.accountNumber<<" to Acount"<<accountNumber
			          <<endl;
			          return NewAccount;
		}
		
		void displayNewdetails()
		{
			cout<<"NewAccount "<<accountNumber<<" Balance :Rupees "<<balance<<endl;

		}
		
		
		Account operator -(double amount)
		{
			Account NewAccount(accountNumber,balance - amount);
			cout<<"Withdrawing rupees "<<amount<<" from Account"<<accountNumber<<endl;
			          return NewAccount;
		}
};

int main()
{
	Bank b;
	b.deposit(5000);
	b.deposit(1500.75);
	b.deposit(2500);
	
	
	Account account1(1,10000);
	Account account2(2,5000);
	
	account1.displayDetails();
	account2.displayDetails();
	
	account1 = account1 + account2;
	account1.displayNewdetails();
	account2.displayNewdetails();
	
	account1 = account1 - 2000;
	account1.displayDetails();
	
	return 0;
}
