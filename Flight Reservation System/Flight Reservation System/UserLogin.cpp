#include "UserLogin.h"
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
void UserLogin:: Login()//gets username and password for login
{
	system("cls");
	cout << "\n\n\t\t\tUser Name : ";
	getline(cin, loginName);
	cout << "\t\t\tPassword : ";
	getline(cin, loginPassword);
}

//checks validity of username and password
void UserLogin::CheckUserNameandPassword(string username, string password, bool& success)
{
	fstream UserName, Password; int count = 0;
	string name,pass;
	UserName.open(username, ios::in | ios::app);
	Password.open(password, ios::in | ios::app);
	while (UserName.good() && Password.good())
	{
		UserName >> name;
		Password >> pass;
		if (name == loginName && pass == loginPassword)
		{
			success = true;
			break;
		}	
	}
	UserName.close();
	Password.close();
	
}
