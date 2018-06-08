#include "Booking.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void Booking::BookFlights()
{
	fstream destination; int number, count = 0; string name;
	destination.open("Destinations.txt", ios::in | ios::out);
	if (!destination.is_open())
	{
		cout << "Error while opening File!" << endl;
	}
	else
	{
		int i=0;
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
			cout << "\t\t\tWhich Flight Do you want to Book?";
			cin >> number;
		} while (number<0||number>i-2);//gets input inside the given range of available flights
		
		i = 0;
		while (destination.good())
		{
			string line;
			getline(destination, line);
			if (number==count && number>0)
			{
				system("cls");
				fstream seats(line + ".txt", ios::in | ios::out);//opens seats file for selected flight
				int c=0;
				//shows seats
				while (seats.good())
				{
					i++;
					string l;
					getline(seats, l);
					cout << l << endl;
					
				}
				seats.close();
				do
				{
					cout << "\t\t\tWhich seat do you want to Book?";
					cin >> number;
				} while (number<0||number>i-2);
				
				int st = 0;
				seats.open(line + ".txt", ios::in | ios::out);
				//books seat
				while (seats.good())
				{
					string l;
					
					if (number==c && number>0)
					{
						string status;
						int len;
						len = seats.tellg();
						seats.seekg(len + 31);
						seats >> status;
						if (status=="Yes")
						{
							seats.seekp(len + 31);
							seats << "No ";
						}
						else
						{
							cout << "\t\t\tSorry Seat is Not Available!";
							st = 1;
						}
						
						break;
					}
					getline(seats, l);
					c++;
				}
				seats.close();
				c = 0;
				if(st==0)
				{
					seats.open(line + ".txt", ios::in | ios::out);
					while (seats.good())
					{
						string l;
					
						if (number == c && number>0)
						{
							int len;
							cout << "\t\t\tEnter User Name : ";
							cin >> name;
							len = seats.tellg();
							seats.seekp(len + 55);
							seats << name+"       ";
							cout << "\t\t\tFlight Booked Successfuly" << endl;
							break;
						}
						getline(seats, l);
						c++;
					}
				}
				break;
			}
			count++;
		}
		system("pause");
	}
}
void Booking::CancelFlights()
{
	fstream destination; int number, count = 0; string name;
	destination.open("Destinations.txt", ios::in | ios::out);
	int i = 0;
	system("cls");
	while (destination.good())
	{
		i++;
		string line;
		getline(destination, line);
		cout <<"("<<i-1<<") "<< line << endl;
	}
	destination.close();
	destination.open("Destinations.txt", ios::in | ios::out);
	do
	{
		cout << "\t\t\tWhich Flight Do you want to Cancel?";
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
			do
			{
				cout << "\t\t\tWhich seat do you want to Cancel?";
				cin >> number;
			} while (number<0 || number>i - 2);
			int st = 0;
			seats.open(line + ".txt", ios::in | ios::out);
			while (seats.good())
			{
				string l;
				if (number == c && number>0)
				{
					string status;
					int len;
					len = seats.tellg();
					seats.seekg(len + 31);
					seats >> status;
					if (status == "No")
					{
						seats.seekp(len + 31);
						seats << "Yes";
					}
					else
					{
						cout << "\t\t\tSorry This is Already not Booked!";
						st = 1;
					}
					break;
				}
				getline(seats, l);
				c++;
			}
			seats.close();
			c = 0;
			if (st == 0)
			{
				seats.open(line + ".txt", ios::in | ios::out);
				while (seats.good())
				{
					string l;
					if (number == c && number>0)
					{
						int len;
						len = seats.tellg();
						seats.seekp(len + 55);
						seats << "None               ";
						cout << "\t\t\tFlight Canceled Successfuly" << endl;
						break;
					}
					getline(seats, l);
					c++;
				}
			}
			break;
		}
		count++;
	}

	system("pause");
}
