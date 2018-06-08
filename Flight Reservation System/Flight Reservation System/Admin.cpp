#include "Admin.h"
#include<iostream>
#include<string>
#include<fstream>//for file handling
#include<conio.h>//for _getch()
#include<iomanip>//for setw()

using namespace std;
void Admin::AddDestination()//adds new destinations
{
	fstream destination; char decision = 'y'; int a = 0;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\tFrom : ";
		cin>>from;
		cout << "\t\t\tTo : ";
		cin>>to;
		cout << "\t\t\tDeparture :";
		cin>>departure;
		cout << "\t\t\tFlight Number : ";
		cin>>flightNumber;
		destination.open("Destinations.txt", ios::in | ios::out | ios::app);//opens flights destinations file
		seatsfile = from.substr(0,3) + "                    " + to.substr(0,3) +  "                    " + departure.substr(0,4) + "                    " + flightNumber.substr(0,5);
		while (destination.good())
		{
			string line;
			getline(destination, line);
			if (line==seatsfile)//checks if file already exists or not
			{
				cout << "\t\t\tFlight Already Exists" << endl;
				cout << "\t\t\tPress y to Replace or n to create another" << endl;
				decision = _getch();
				while (decision != 'n' && decision != 'N')
				{
					if (decision == 'y' || decision == 'Y')
					{
						seats(seatsfile);//replaces seats for existing flight
						a = 1;
						break;
					}
					decision = _getch();
				}
				a = 1;
				break;
			}
			decision = 'y';
			a = 0;
		}
		destination.close();
		if ((decision == 'y' || decision == 'Y') && a==0)//executes when flight not exists before
		{
			destination.open("Destinations.txt", ios::in | ios::out | ios::app);
			//sets new destination 
			destination << from.substr(0, 3) + "                    " + to.substr(0, 3) + "                    " + departure.substr(0, 4) + "                    " + flightNumber.substr(0, 5) << endl;
			//sets seats for new flight
			seats(seatsfile);
			destination.close();
			break;
		}
		else if (decision == 'y' || decision == 'Y')
		{
			break;
		}
	}
}
void Admin::seats(string file)//for setting seats for new flight
{
	fstream seat(file + ".txt", ios::out); int j=0;
	seat << "   Seat Number"<<setw(24)<<"Availablity"<<setw(26)<<"Occupied By"<<endl;
	for (int i = 0; i < 3; i++)
	{
		seat << j + 1 << setw(5) << "A" << i + 1 << "                        Yes                     None               " << endl;
		j++;
	}
	for (int i = 0; i < 3; i++)
	{
		seat << j + 1 << setw(5) << "B" << i + 1 << "                        Yes                     None               " << endl;
		j++;
	}
	for (int i = 0; i < 3; i++)
	{
		seat << j + 1 << setw(5) << "C" << i + 1 << "                        Yes                     None               " << endl;
		j++;
	}
	for (int i = 0; i < 3; i++)
	{
		seat << j + 1 << setw(4) << "D" << i + 1 << "                        Yes                     None               " << endl;
		j++;
	}
}

void Admin::ShowSeats()//shows seats for perticular flight
{
	fstream destination; int number, count = 0;
	destination.open("Destinations.txt", ios::in | ios::out);
	int i = 0;
	system("cls");
	while (destination.good())
	{
		i++;
		string line;
		getline(destination, line);
		cout << "(" << i - 1 << ") " << line << endl;
	}
	destination.close();
	destination.open("Destinations.txt", ios::in | ios::out);
	do
	{
		cout << "\t\t\tWhich Flight's Seats Do you want to see?";
		cin >> number;
	} while (number<0 || number>i - 2);

	i = 0;
	while (destination.good())
	{
		string line;
		getline(destination, line);
		if (number == count && number>0)
		{
			system("cls");
			fstream seats(line + ".txt", ios::in | ios::out);
			int c = 0;
			while (seats.good())
			{
				i++;
				string l;
				getline(seats, l);
				cout << l << endl;
			}
			seats.close();
			break;
		}
		count++;
	}

	system("pause");
}
void Admin::DeleteDestination()//Deletes existing flights
{
	fstream destination;
	int number, count = 0,i = 0;
	string deleteline;
	destination.open("Destinations.txt", ios::in | ios::out);
	system("cls");
	while (destination.good())
	{
		i++;
		string line;
		getline(destination, line);
		cout << "(" << i - 1 << ") " << line << endl;
	}
	destination.close();
	destination.open("Destinations.txt", ios::in | ios::out);
	do
	{
		cout << "\t\t\tWhich Flight Do you want to Delete?";
		cin >> number;
	} while (number<0 || number>i - 2);

	while (destination.good())
	{
		string line;
		getline(destination, line);
		if (number == count && number>0)
		{
			int len;
			len = destination.tellg();
			
			deleteline = line;
			break;
		}
		
		count++;
	}
	destination.close();
	destination.open("Destinations.txt", ios::in | ios::out);
	ofstream temp;
	temp.open("temp.txt");
	while (destination.good())
	{
		string a;
		while (getline(destination, a))
		{
			if (a != deleteline)
			{
				temp << a << endl;
			}
		}
	}
	

	temp.close();
	destination.close();
	remove("Destinations.txt");
	rename("temp.txt", "Destinations.txt");
	deleteline += ".txt";
	remove(deleteline.c_str());
	cout << "\t\t\tFlight Deleted Successfuly" << endl;
	system("pause");
}
