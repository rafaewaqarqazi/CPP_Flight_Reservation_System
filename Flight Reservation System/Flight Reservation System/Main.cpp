#include<iostream>
#include<conio.h>//for _getch()
#include<fstream>//for file handling
#include"Menu.h"
#include"Selection.h"
using namespace std;


int main()
{
	system("color A");//for changing console color
	Menu menu; Selection select;
	bool c = true;
	do
	{
		menu.MainMenu();//shows main menu
		select.MainMenuSelection(c);//perfoms operations on main menu
	} while (c);//executes until c is true
	
	system("pause");
	return 0;
}
