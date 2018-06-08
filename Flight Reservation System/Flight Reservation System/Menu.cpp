#include "Menu.h"
#include<iostream>
using namespace std;


void Menu::MainMenu()
{
	system("cls");
	cout << "\n\n\t\t\t*******MAIN MENU*******\n" << endl;
	cout << "\t\t\tChoose From below:" << endl;
	cout << "\t\t\t[1] Login as Adminitrator" << endl;
	cout << "\t\t\t[2] Login as Registered User" << endl;
	cout << "\t\t\t[3] Continue as a Guest\n\t\t\t[Esc] Exit" << endl;
	cout << "\n\t\t\tSelect your Option : ";
}
void Menu::AdminMenu()
{
	system("cls");
	cout << "\n\n\t\t\t*******ADMINISTRATOR*******\n" << endl;
	cout << "\t\t\tChoose From below:" << endl;
	cout << "\t\t\t[1] Add Destination" << endl;
	cout << "\t\t\t[2] Delete Destination" << endl;
	cout << "\t\t\t[3] Show Flights" << endl;
	cout << "\t\t\t[4] Book Flight" << endl;
	cout << "\t\t\t[5] Cancel Flight" << endl;
	cout << "\t\t\t[6] See Flight Seats" << endl;
	cout << "\t\t\t[Esc] Exit" << endl;
	cout << "\n\t\t\tSelect your Option : ";
}
void Menu::RegUserMenu()
{
	system("cls");
	cout << "\n\n\t\t\t*******USER*******\n" << endl;
	cout << "\t\t\tChoose From below:" << endl;
	cout << "\t\t\t[1] Show Flights" << endl;
	cout << "\t\t\t[2] Book Flight" << endl;
	cout << "\t\t\t[3] Cancel Flight" << endl;
	cout << "\t\t\t[Esc] Back to Main Menu" << endl;
	cout << "\n\t\t\tSelect your Option : ";
}
void Menu::GuestMenu()
{
	system("cls");
	cout << "\n\n\t\t\t*******GUEST*******\n" << endl;
	cout << "\t\t\tChoose From below:" << endl;
	cout << "\t\t\t[1] Show Flights" << endl;
	cout << "\t\t\t[2] Book Flight" << endl;
	cout << "\t\t\t[3] Create Account" << endl;
	cout << "\t\t\t[Esc] Back to Main Menu" << endl;
	cout << "\n\t\t\tSelect your Option : ";
}