#include<iostream>
using namespace std;
int acc;
int pin;
int bal = 0;
char l;

bool login() {
	cout<<"----------------------------------hello this is WHalen Bank of Dubai------------------------\n\n\n\n";
	cout<<"\t\t\t\t\t\tloading\n\n\n\n\n\n";
	cout<<"\t\t\t\t:Please enter any number or character to proceed:";
	cin>>l;
	cout<<"create acc number:";
	cin>>acc;
	cout<<"create pin:";
	cin>>pin;
	int givenacc = -1;
	int givenpin = -1;
	bool isAccountInvalid = true;
	bool isPinInvalid = true;
	
	cout << "Welcome!" << endl;
	
	while (isAccountInvalid) {
		
		cout << "Please enter your account number: ";
		cin >> givenacc;
		
		if (givenacc == acc) {
			isAccountInvalid = false;
		} else {
			cout << "Invalid account number! Try again." << endl;
		}
	}

	while (isPinInvalid) {
		
		cout << "Enter your PIN: ";
		cin >> givenpin;
		
		if (givenpin == pin) {
			isPinInvalid = false;
		} else {
			cout << "Invalid PIN number! Try again." << endl;
		}

	}

	return true;
		
}

int getUserOption () {

	int selectedOption = -1;

	cout << "Main menu:" << endl;
	cout << "	1 - my balance" << endl;
	cout << "	2 - Withdraw cash" << endl;
	cout << "	3 - Deposit" << endl;
	cout << "	4 - Exit" << endl;
	cout << "Enter a choice: " << endl;
	cin >> selectedOption;
	
	return selectedOption;
	
}

void viewbal () {

	cout << "You have:" << endl;
	cout << "$" << bal << endl;

}

void withdrawCash() {
	
	int selectedOption = -1;
	int valueToWithdraw =0;
	bool isNotFinished = true;

	do {
		
		cout << "Withdrawal options:" << endl;
		cout << "1 - $10" << endl;
		cout << "2 - $100" << endl;
		cout << "3 - $250" << endl;
		cout << "4 - $500" << endl;
		cout << "5 - $1000" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "choose a withdrawal option (1-6)" << endl;

		cin >> selectedOption;
		switch (selectedOption) {
			case 1:
				valueToWithdraw = 10;
				break;
			case 2:
				valueToWithdraw = 100;
				break;
			case 3:
				valueToWithdraw = 250;
				break;
			case 4:
				valueToWithdraw = 500;
				break;
			case 5:
				valueToWithdraw = 1000;
				break;
			case 6:
				isNotFinished = false;
				break;
			default:
				cout << "Invalid option! Try again." << endl;
				break;
		} 
		
		if (valueToWithdraw != 0) {
			if (valueToWithdraw > bal) {
				cout << "You just have $" << bal << ". You can't withdraw $" << valueToWithdraw << endl;
			} else {
				cout<<"\t\t\t\t\tYour Transaction was successfully been withdraw!!\n\n\n\n\n";
				cout<<"\t----------------------------------Thank You for banking with us :)-----------------------------------------------\n";
				bal = bal - valueToWithdraw;
				isNotFinished = false;
			}
			valueToWithdraw = 0;
		}

	} while (isNotFinished);	

}

void depositFunds() {

	int selectedOption = -1;	
	bool isNotFinished = true;

	do {
		
		cout << "Deposit options:" << endl;
		cout << "1 - $10" << endl;
		cout << "2 - $100" << endl;	
		cout << "3 - $250" << endl;
		cout << "4 - $500" << endl;
		cout << "5 - $1000" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "choose a deposit option (1-6)" << endl;

		cin >> selectedOption;
		switch (selectedOption) {
			case 1:
				bal = bal + 10;
				isNotFinished = false;
				break;
			case 2:
				bal = bal + 100;
				isNotFinished = false;
				break;
			case 3:
				bal = bal + 250;
				isNotFinished = false;
				break;
			case 4:
				bal = bal + 500;
				isNotFinished = false;
				break;
			case 5:
				bal = bal + 1000;
				isNotFinished = false;	
				break;
			case 6:
				isNotFinished = false;
				break;
			default:
				cout << "Invalid option! Try again." << endl;
				break;
		} 
		
	} while (isNotFinished);

}

int main () {
				
	if (login()) {
		
		int isNotFinished = true;

		do {
			
			switch (getUserOption()) {
				case 1:
					viewbal();
					break;
				case 2:
					withdrawCash();
					break;
				case 3:
					depositFunds();
					break;
				case 4:
					isNotFinished = false;
					break;
				default:
					cout << "Invalid option! Try again." << endl;
					break;
			}

		} while (isNotFinished);

	}

	return 0;

}
