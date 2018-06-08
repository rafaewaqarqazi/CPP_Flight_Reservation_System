#include "Registration.h"
#include<iostream>
#include<string>
#include<fstream>//for file handling
using namespace std;
void Registration::UserRegistration()
{
	int c=0;//its value will change if username already exists
	//opening files for storing username and password
	fstream username("UserName.txt", ios::in | ios::out | ios::app), password("Password.txt",ios::in | ios::out | ios::app);
	
	while (c !=2)
	{
		system("cls");
		cout << "\n\n\t\t\tUser Name: ";
		getline(cin, NewName);//gets new username from user
		cout << "\t\t\tPassword : ";
		getline(cin, NewPassword);//gets new password from user
		
		c = 0;
		while (username.good())
		{
			string n;
			username >> n;//getting line from file to check new username
			if (n == NewName)
			{
				cout << "\t\t\tUser Name Already Exists!" << endl;
				cout << "\t\t\tPlease Enter Different User Name" << endl;
				system("pause");
				c = 1;
				break;
			}
		}
		username.close();//closing file
		username.open("UserName.txt", ios::in | ios::out | ios::app);//opening file username.txt
		if (c == 0)
		{
			username << NewName << endl;
			password << NewPassword<<endl;
			cout << "\t\t\tSuccessfuly Registered!\n\t\t\t"<<endl;
			system("pause");
			c=2;
		}
	}
	//closing files
	username.close();
	password.close();
	
}

