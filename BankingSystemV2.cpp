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
bool strdigit2(string);
void show_mess1();
string typConvert(int);
void reportThis(int);
void reportAll(int);

int numOfData = 5;
string ACnum[100] = { "8775473967","6683977666","4723954794","5242242671","1286764136" };
string ACname[100] = { "Mr.A","Mr.B","Mr.C","Mr.D","Mr.E" };
double ACmoney[100] = { 100000.00,15200.79,95370.32,456132.52,95000.50 };
int ACtype[100] = { 1,1,2,3,3 };
string ACreport[100];


int main() {
	bool mainloop = false;
	do {
		system("cls");
		cout << " __        __         _                                       _               ____       _      _   _   _  __\n";
		cout << " \\ \\      / /   ___  | |   ___    ___    _ __ ___     ___    | |_    ___     | __ )     / \\    | \\ | | | |/ /\n";
		cout << "  \\ \\ /\\ / /   / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\   | __|  / _ \\    |  _ \\    / _ \\   |  \\| | | ' / \n";
		cout << "   \\ V  V /   |  __/ | | | (__  | (_) | | | | | | | |  __/   | |_  | (_) |   | |_) |  / ___ \\  | |\\  | | . \\ \n";
		cout << "    \\_/\\_/     \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___|    \\__|  \\___/    |____/  /_/   \\_\\ |_| \\_| |_|\\_\\\n\n";
		string inAcNum;
		bool inchek = false;
		do {
			cout << "Enter account number: ";
			//cin >> inAcNum;
			getline(cin, inAcNum);
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
				//cin >> choi;
				getline(cin, choi);
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
	system("CLS");
	string inname;
	bool chekname = false;
	//name
	do {
		cout << "Enter the name of your account\n";
		cout << "==>";
		//cin >> inname;
		getline(cin, inname);
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
	//int intype;
	string intype;
	bool chektype;
	do {
		cout << "==>";
		//cin >> intype;
		getline(cin, intype);
		if (intype == "1" || intype == "2" || intype == "3") {
			chektype = false;
		}
		else {
			cout << "Out of choice, ";
			cout << "Please try again\n";
			chektype = true;
		}
	} while (chektype);
	ACname[numOfData] = inname;
	ACnum[numOfData] = acnumber;
	ACtype[numOfData] = stoi(intype);
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
		system("cls");
		cout << "\nHallo " << ACname[i] << endl;
		cout << "Your Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht";
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
			//cin >> choi;
			getline(cin, choi);
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
				cout << "Out of choice, ";
				cout << "Please try again\n";
				chekchoi = true;
			}
		} while (chekchoi);
	} while (menu);
}
//menu deposit
void deposit(int i) {
	system("cls");
	double inmoney;
	string sinmoney;
	//cout << "\nYour Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	cout << "-------------------------------------\n";
	cout << "Enter the amount of money you want to deposit.(-1 back to main menu)\n";
	//check input is digit
	bool chekinput;
	bool exitchek = true;
	do {
		cout << "==> ";
		//cin >> sinmoney;
		getline(cin, sinmoney);
		if (sinmoney == "-1") {
			chekinput = false;
			exitchek = false;
		}
		else if (strdigit2(sinmoney) == false) {
			chekinput = false;
		}
		else {
			chekinput = true;
			cout << "ERROR, Please try again\n";
		}
		//chekinput = strdigit2(sinmoney);
	} while (chekinput);
	if (exitchek) {
		inmoney = stod(sinmoney);
		cout << "-------------------------------------\n";
		ACmoney[i] += inmoney;
		ACreport[i] += ("    Deposit___________________________________+" + sinmoney + " Baht\n");
		cout << "\tDeposit completed\n\n";
		system("pause");
		//cout << "Your Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	}
}
//menu wihtdraw
void withdraw(int i) {
	system("cls");
	double inmoney;
	string sinmoney;
	bool flagloop;
	bool exitchek = true;
	//cout << "\nYour Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	do {
		cout << "-------------------------------------\n";
		cout << "Enter the amount of money you want to withdraw.(-1 back to main menu)\n";
		//check input is digit
		bool chekinput;
		do {
			cout << "==> ";
			//cin >> sinmoney;
			getline(cin, sinmoney);
			if (sinmoney == "-1") {
				exitchek = false;
				chekinput = false;
			}
			else if (strdigit2(sinmoney) == false) {
				chekinput = false;
			}
			else {
				cout << "ERROR, Please try again\n";
				chekinput = true;
			}
			//chekinput = strdigit2(sinmoney);
		} while (chekinput);
		if (exitchek) {
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
		}
		else {
			flagloop = false;
		}
	} while (flagloop);
	if (exitchek) {
		ACreport[i] += ("    Wihtdraw__________________________________-" + sinmoney + " Baht\n");
		cout << "\tWithdraw completed\n\n";
		system("pause");
		//cout << "Your Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	}
}
//menu tranfer
void transfer(int i) {
	system("cls");
	string inAcnum;
	string sinmoney;
	double inmoney;
	bool flagLoop = true, accuracy;
	bool exitchek = true;
	//cout << "\nYour Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	do {
		cout << "-------------------------------------\n";
		cout << "Enter account number (-1 back to main menu) : ";
		//cin >> inAcnum;
		getline(cin, inAcnum);
		//check input is digit
		if (inAcnum == "-1") {
			flagLoop = false;
			exitchek = false;
		}
		else {
			bool chekinput;
			do {
				cout << "amount : ";
				//cin >> sinmoney;
				getline(cin, sinmoney);
				chekinput = strdigit2(sinmoney);
			} while (chekinput);
			inmoney = stod(sinmoney);
			cout << "-------------------------------------\n";
			for (int j = 0; j < 100; j++) {
				if (inAcnum == ACnum[j]) {
					if (inmoney <= ACmoney[i]) {
						ACmoney[i] -= inmoney;
						ACmoney[j] += inmoney;
						ACreport[j] += ("    Received from " + ACnum[i] + "__________________+" + sinmoney + " Baht\n");
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
			if (flagLoop) {
				if (accuracy == true) {
					cout << "\t!Wrong account number!\n";
				}
				else if (accuracy == false) {
					cout << "\tYour money is not enough\n";
				}
				cout << "\tPlease try again\n";
			}
		}
	} while (flagLoop);
	if (exitchek) {
		ACreport[i] += ("    Transferred to " + inAcnum + "_________________-" + sinmoney + " Baht\n");
		cout << "\tTransfer completed\n\n";
		system("pause");
		//cout << "Your Balance : " << fixed << setprecision(2) << ACmoney[i] << " Baht" << endl;
	}
}
//menu report
void report(int i) {
	system("cls");
	string choi;
	bool chek;
	cout << "\n1.View Report This Account\n";
	cout << "2.View Report All Account\n";
	do {
		cout << "==>";
		getline(cin, choi);
		if (choi == "1") {
			reportThis(i);
			chek = false;
		}
		else if (choi == "2") {
			reportAll(i);
			chek = false;
		}
		else {
			cout << "Out of choice, ";
			cout << "Please try again\n";
			chek = true;
		}
	} while (chek);
	system("pause");
}

void reportThis(int i) {
	system("cls");
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
}
void reportAll(int i) {
	system("cls");
	cout << "There are " << numOfData << " accounts in this bank.\n";
	cout << "-----------------------------\n";
	for (int j = 0; j < numOfData; j++) {
		cout << "\tAccount " << j + 1 << " info\n";
		cout << "\t   Account Type : ";
		cout << typConvert(ACtype[j]) << endl;
		cout << "\t   Account NUMBER : ";
		cout << ACnum[j] << endl;
		cout << "\t   Account NAME : ";
		cout << ACname[j] << endl;
		cout << "\t   Account Balance : ";
		cout << ACmoney[j] << endl;
		cout << "\n  Account " << j + 1 << " history\n";
		if (ACreport[j] == "") {
			cout << "    --NO HISTORY--\n";
		}
		else {
			cout << ACreport[j];
		}
		cout << "-----------------------------\n";
	}
}

//message1
void show_mess1() {
	cout << "\tWrong account number format\n";
	cout << "\t* Must be 10 digits only\n";
	cout << "\tPlease try again\n";
}

//check string digit (true for is digit)
bool strdigit(string a) {
	bool check = true;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a.at(i)) == 0) {
			check = false;
			break;
		}
		else {
			check = true;
		}
	}
	return(check);
}
//check string digit(decimal) (false for is digit)
bool strdigit2(string a) {
	bool check = true;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a.at(i)) != 0 || a.at(i) == '.') {
			check = false;
		}
		else {
			check = true;
			break;
		}
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