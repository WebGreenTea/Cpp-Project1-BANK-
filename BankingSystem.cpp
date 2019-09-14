#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
void bank_menu(int);
void deposit(int);
void withdraw(int);
void transfer(int);
void report(int);
void createAC(string);
bool chekinput(string);
bool strdigit(string);
void show_mess1();
string typConvert(int);

int numOfData = 5;
string ACnum[100] = { "8775473967","6683977666","4723954794","5242242671","1286764136" };
string ACname[100] = { "mr.a","mr.b","mr.c","mr.d","mr.e" };
double ACmoney[100] = { 100000.00,15200.79,95370.32,456132.52,95000.50 };
int ACtype[100] = { 1,1,2,3,3 };
string ACreport[100];


int main() {
	bool mainloop = false;
	do {
		cout << " __        __         _                                       _               ____       _      _   _   _  __\n";
		cout << " \\ \\      / /   ___  | |   ___    ___    _ __ ___     ___    | |_    ___     | __ )     / \\    | \\ | | | |/ /\n";
		cout << "  \\ \\ /\\ / /   / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\   | __|  / _ \\    |  _ \\    / _ \\   |  \\| | | ' / \n";
		cout << "   \\ V  V /   |  __/ | | | (__  | (_) | | | | | | | |  __/   | |_  | (_) |   | |_) |  / ___ \\  | |\\  | | . \\ \n";
		cout << "    \\_/\\_/     \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___|    \\__|  \\___/    |____/  /_/   \\_\\ |_| \\_| |_|\\_\\\n\n";
		string inAcNum;
		bool inchek = false;
		do {
			
			cout << "Enter account number: ";
			cin >> inAcNum;
			if (inAcNum.length() == 10) {
				if (strdigit(inAcNum) == false) {
					inchek = true;
					show_mess1();
				}
				else {
					inchek = false;
				}
			}
			else if (inAcNum.length() != 10) {
				inchek = true;
				show_mess1();
			}
		} while (inchek);
		//chack have account?
		bool flag = false;
		for (int i = 0; i < 100; i++) {
			if (ACnum[i] == inAcNum) {
				flag = true;
				bank_menu(i);
				mainloop = true;
				break;
			}
			else {
				flag = false;

			}
		}
		//if no account
		if (flag == false) {
			string choi;
			cout << "This account number does not exist in the system.\n";
			bool createlop;
			do {
				cout << "Do you want to create an account? (y/n)\n";
				cin >> choi;
				if (choi == "y" || choi == "Y") {
					createAC(inAcNum);
					createlop = false;
					mainloop = true;
				}
				else if (choi == "n" || choi == "N") {
					createlop = false;
					mainloop = true;
				}
				else {
					createlop = true;
				}
			} while (createlop);

		}
	} while (mainloop);
	cout << "End";
	return 0;
}
//create account
void createAC(string acnumber) {
	string inname;
	bool chekname = false;
	//name
	do {
		cout << "Enter the name of your account\n";
		cout << "==>";
		cin >> inname;
		for (int i = 0; i < 100; i++) {
			if (ACname[i] == inname) {
				cout << "That name already exists\n";
				chekname = true;
				break;
			}
			else {
				chekname = false;
			}
		}
	} while (chekname == true);
	
	cout << "\nSelect Account Type\n";
	cout << "\t1.Savings Bank Account\n";
	cout << "\t2.Current Deposit Account\n";
	cout << "\t3.Fixed Deposit Account\n";
	int intype;
	bool chektype;
	do {
		cout << "==>";
		cin >> intype;
		if (intype == 1 || intype == 2 || intype == 3) {
			chektype = false;
		}
		else {
			chektype = true;
		}
	} while (chektype);
	ACname[numOfData] = inname;
	ACnum[numOfData] = acnumber;
	ACtype[numOfData] = intype;
	numOfData += 1;
	cout << "Your account has been created.\n";
	cout << "\tYour account info\n";
	cout << "\t   Account Type : ";
	cout << typConvert(ACtype[numOfData - 1]) << endl;
	cout << "\t   Account NUMBER : ";
	cout << ACnum[numOfData - 1] << endl;
	cout << "\t   Account NAME : ";
	cout << ACname[numOfData - 1] << endl;
	cout << "\t   Account Balance : ";
	cout << ACmoney[numOfData - 1] << endl;
	system("pause");
}

//main menu
void bank_menu(int i) {
	bool menu;
	do {
		cout << "\n----------menu----------\n";
		string choi;
		cout << "1.Deposit\n";
		cout << "2.Withdraw\n";
		cout << "3.Transfer\n";
		cout << "4.Report\n";
		cout << "5.Exit\n";
		bool chekchoi = false;
		do {
			cout << "Enter your Choice : ";
			cin >> choi;
			if (choi == "1") {
				deposit(i);
				menu = true;
				chekchoi = false;
			}
			else if (choi == "2") {
				withdraw(i);
				menu = true;
				chekchoi = false;
			}
			else if (choi == "3") {
				transfer(i);
				menu = true;
				chekchoi = false;
			}
			else if (choi == "4") {
				report(i);
				menu = true;
				chekchoi = false;
			}
			else if (choi == "5") {
				menu = false;
				chekchoi = false;
			}
			else {
				chekchoi = true;
			}

		} while (chekchoi);
	} while (menu);
}
//menu deposit
void deposit(int i) {
	double inmoney;
	string sinmoney;
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	cout << "-------------------------------------\n";
	cout << "Enter the amount of money you want to deposit.\n";
	cout << "==> ";
	cin >> sinmoney;
	inmoney = stod(sinmoney);
	cout << "-------------------------------------\n";
	ACmoney[i] += inmoney;
	ACreport[i] += ("    Deposit___________________________________+" + sinmoney + " Baht\n");
	cout << "\tDeposit completed\n";
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
}
//menu wihtdraw
void withdraw(int i) {
	double inmoney;
	string sinmoney;
	bool flagloop;
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	do {
		cout << "-------------------------------------\n";
		cout << "Enter the amount of money you want to withdraw.\n";
		cout << "==> ";
		cin >> sinmoney;
		inmoney = stod(sinmoney);
		cout << "-------------------------------------\n";
		if (inmoney <= ACmoney[i]) {
			ACmoney[i] -= inmoney;
			flagloop = false;
		}
		else {
			cout << "Your amount is not enough.\n";
			flagloop = true;
		}
	} while (flagloop);
	ACreport[i] += ("    Wihtdraw__________________________________-" + sinmoney + " Baht\n");
	cout << "\tWithdraw completed\n";
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
}
//menu tranfer
void transfer(int i) {
	string inAcnum;
	string sinmoney;
	double inmoney;
	bool flagLoop = true , accuracy;
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	do {
		cout << "-------------------------------------\n";
		cout << "Enter account number : ";
		cin >> inAcnum;
		cout << "amount : ";
		cin >> sinmoney;
		inmoney = stod(sinmoney);
		cout << "-------------------------------------\n";
		for (int j = 0; j < 100; j++) {
			if (inAcnum == ACnum[j]) {
				if (inmoney <= ACmoney[i]) {
					ACmoney[i] -= inmoney;
					ACmoney[j] += inmoney;
					ACreport[j] += ("    Received from " + inAcnum + "__________________+" + sinmoney + " Baht\n");
					flagLoop = false;
					break;
				}
				else {
					flagLoop = true;
					accuracy = false;
					break;
				}
			}
			else {
				flagLoop = true;
				accuracy = true;
			}
		}
		if (flagLoop){
			if (accuracy == true) {
				cout << "\t!Wrong account number!\n";
			}
			else if (accuracy == false) {
				cout << "\tYour money is not enough\n";
			}
			cout << "\tPlease try again\n";
		}
	} while (flagLoop);
	ACreport[i] += ("    Transferred to "+inAcnum+"_________________-" + sinmoney + " Baht\n");
	cout << "\tTransfer completed\n";
	cout << "your current money : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
}
//menu report
void report(int i) {
	cout << "-----------------------------\n";
	cout << "\tYour account info\n";
	cout << "\t   Account Type : ";
	cout << typConvert(ACtype[i]) << endl;
	cout << "\t   Account NUMBER : ";
	cout << ACnum[i] << endl;
	cout << "\t   Account NAME : ";
	cout << ACname[i] << endl;
	cout << "\t   Account Balance : ";
	cout << ACmoney[i] << endl;
	cout << "\n  Your history\n";
	if (ACreport[i] == "") {
		cout << "    --NO HISTORY--\n";
	}
	else {
		cout << ACreport[i];
	}
	system("pause");
}

//message1
void show_mess1() {
	cout << "\tWrong account number format\n";
	cout << "\t* Must be 10 digits only\n";
	cout << "\tPlease try again\n";
}

//check string digit
bool strdigit(string a) {
	bool check = true;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a.at(i)) == 0) {
			check = false;
			break;
		}
		check = true;
	}
	return(check);
}

string typConvert(int X) {
	string out;
	if (X == 1) {
		out = "Savings Bank Account";
	}
	else if (X == 2) {
		out = "Current Deposit Account";
	}
	else if (X == 3) {
		out = "Fixed Deposit Account";
	}
	else {
		out = "ERROR";
	}
	return(out);
}