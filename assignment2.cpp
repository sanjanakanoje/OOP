#include<iostream>
using namespace std;

class BankAccount{
	private :
		int accountNumber;
		string accountHolderName;
		string accountType;
		double balance;
	
	public :
		
		//creating a constructor...
		BankAccount(int accountNumber,
		string accountHolderName,
		string accountType,
		double balance){
			this -> accountNumber = accountNumber;
			this -> accountHolderName = accountHolderName; 
			this -> accountType = accountType;
			this -> balance = balance; 
		}
		
		//function for get Account Number...
		int getAccountNumber(){
			return accountNumber;			
		}
		
		//function for get Account Holder Name...
		string getAccountHolderName(){
			return accountHolderName;			
		}
		
		//function for get Account Type...
		string getAccountType(){
			return accountType;			
		}
		
		//function for get Account balace...
		double getBalance(){
			return balance;			
		}
		
		//function for deposite money
		void deposite(double depositeAmount){
			balance += depositeAmount;
			cout<<"Deposite successfully. Updated Balance = "<<balance<<endl;
		}
		
		//function for withdraw money
		void withdraw(double withdrawAmount){
			if(balance >= withdrawAmount){
			balance -= withdrawAmount;
			cout<<"withdraw successfully."<<endl<<"Updated Balance = "<<balance<<endl;
			}
			else{
				cout<<"Unsufficient balance."<<endl;
			}
		}
		
		//function to display account details...
		void displayAccountDetails(){
			cout<<"Account Number : "<<accountNumber<<endl;
			cout<<"Account Holder Name : "<<accountHolderName<<endl;
			cout<<"Account Type : "<<accountType<<endl;
			cout<<"Account Balance : "<<balance<<endl;
		}
};

int main()
{
	string accountHolderName,accountType;
	int accountNumber,choice;
	double balance;
	
	cout<<"Enter Your Account Number : ";
	cin>>accountNumber;
	
	cout<<"Enter Account Holder Name : ";
	cin>>accountHolderName;
	
	cout<<"Enter Account Type : ";
	cin>>accountType;
	
	cout<<"Enter current Balance : ";
	cin>>balance;
	
	BankAccount account(accountNumber,accountHolderName,accountType,balance);
	
	while(true){
		cout<<endl<<"Enter."<<endl;
		cout<<"1. for Deposite Amount"<<endl;
		cout<<"2. for Withdraw Amount"<<endl;
		cout<<"3. for Display Account Details"<<endl;
		cout<<"4. for exit"<<endl;
		
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice){
			case 1 :
				double depositeAmount;
				cout<<"Enter amount to deposite : ";
				cin>>depositeAmount;
				account.deposite(depositeAmount);
				break;
				
			case 2 :
				double withdrawAmount;
				cout<<"Enter Withdrew amount : ";
				cin>>withdrawAmount;
				account.withdraw(withdrawAmount);
				break;
				
			case 3 :
				account.displayAccountDetails();
				break;
				
			case 4 :
				return 0;
				break;
				
			default : 
				cout<<"Invalid Choice"<<"\t"<<"please try again..."<<endl;
		}
	}
	return 0;
}
