#include "Selection.h"
#include<iostream>
#include<conio.h>//for _getch()
#include"Admin.h"
#include"UserLogin.h"
#include"Guest.h"
#include"Menu.h"
using namespace std;
//Method for Main Menu Operation:
void Selection::MainMenuSelection(bool& c)
{
	char opt; bool a = true, b = true,d=true; Menu menu;
	opt = _getch();//gets value in char to handle charactor and integers:
	cout << endl;
	switch (opt)
	{
	case'1':
	{
		Admin administrator; bool success = false; int count = 0; 
		while (!success)
		{
			administrator.Login();//To login as Administrator
			administrator.CheckUserNameandPassword("adminUserName.txt", "adminPassword.txt", success);//checks username and password
			count++;
			if (count <= 3 && !success)//execute if username or password is incorrect 
			{
				cout << "\t\t\tWrong User Name or Password!" << endl;
				cout << "\t\t\t" << 4 - count << " Tries Remain!\n\t\t\t";
				system("pause");
			}
			if (count == 4 && !success)//execute if login attempts goes upto 3
			{
				cout << "\t\t\tToo many Login Attempts!\n\t\t\t";
				system("pause");
				break;
			}
		}
		if (success)//execute if username and password is correct
		{
			do
			{
				menu.AdminMenu();//shows administrator menu
				AdminSelection(a);//gets input according to menu and performs relevant operation on it
			} while (a);
		}
		
		

	}break;

	case'2':
	{
		UserLogin user; bool success = false; int count = 0; char decision; 
		while (!success)
		{
			user.Login();//user login
			user.CheckUserNameandPassword("UserName.txt", "Password.txt", success);//checke username and password
			count++;
			if (count <= 3 && !success)//executes if username or password is incorrect
			{
				cout << "\t\t\tUser Name or Password Does not Match!" << endl;
				cout << "\t\t\t" << 4 - count << " Tries Remain!\n\t\t\t";
				system("pause");
			}
			if (count == 4 && !success)//executes when login attempts goes upto 3
			{
				cout << "\t\t\tToo many Login Attempts!" << endl;
				cout << "\t\t\tDo you want to Register?(y/n) "<<endl;
				decision = _getch();
				while (decision != 'n' && decision != 'N')
				{
					if (decision == 'y' || decision == 'Y')
					{
						user.UserRegistration();//creates new account for user
						break;
					}
					decision = _getch();
				}
				system("pause");
				break;
			}
			
		}
		if (success)//executes when username and password is correct
		{
			do
			{
				menu.RegUserMenu();//shows Registered user menu
				UserMenuSelection(b);//gets input according to menu and performs relevant operation on it
			} while (b);
		}
		
		
	}break;

	case'3':
	{
		do
		{
			menu.GuestMenu();//shows Guest menu
			GuestSelection(d);//gets input according to menu and performs relevant operation on it
		} while (d);
	}break;

	case 27: 
	{
		c = false;
	}break;

	default:system("cls");
		break;
	}
}

void Selection:: AdminSelection(bool& a)//method of selection of admin menu
{
	char opt; Admin administrator;
	opt = _getch();
	cout << endl;
	switch (opt)
	{
	case'1':
	{
		administrator.AddDestination();//adds new flights
	}break;

	case'2':
	{
		administrator.DeleteDestination();//deletes flights
	}break;
	case'3':
	{
		system("cls");
		administrator.ShowFlights();//shows flights
		system("pause");
	}break;

	case'4':
	{
		administrator.BookFlights();//books flights
	}break;

	case'5':
	{
		administrator.CancelFlights();//cancels flights
	}break;

	case'6':
	{
		administrator.ShowSeats();//shows seats in perticular flight
	}break;
	case 27://executes if user press esc
	{
		a = false;
	}break;
	default:
		break;
	}
}

void Selection::UserMenuSelection(bool& b)
{
	char opt; UserLogin user;
	opt = _getch();
	cout << endl;
	switch (opt)
	{
	case '1':
	{
		system("cls");
		user.ShowFlights();//shows flights
		system("pause");
	}break;
	case'2':
	{
		system("cls");
		user.BookFlights();//books flights
	}break;
	case'3':
	{
		system("cls");
		user.CancelFlights();//cancels flights
	}break;
	case 27:
	{
		b = false;
	}break;
	default:
		break;
	}
}

//Method For Guest User's Operation
void Selection::GuestSelection(bool& d)
{
	char opt; Guest guest;
	opt = _getch();
	cout << endl;
	switch (opt)
	{
	case '1':
	{
		system("cls");
		guest.ShowFlights();//shows flights
		system("pause");
	}break;
	case'2':
	{
		char decision;
		cout << "Sorry you can't book flight! You must Register yourself to book flights!" << endl;
		cout << "Do you want to Register?(y/n)" << endl;
		decision = _getch();
		while (decision != 'n' && decision != 'N')
		{
			if (decision == 'y' || decision == 'Y')
			{
				guest.UserRegistration();//registers guest user to gain access in other operations
				break;
			}
			decision = _getch();
		}
	
	}break;
	
	case'3':
	{
		guest.UserRegistration();//creates new account for new user
	}break;
	case 27:
	{
		d = false;
	}break;
	default:
		break;
	}
}

