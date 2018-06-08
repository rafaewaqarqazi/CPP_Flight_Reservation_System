#include "Guest.h"
#include<fstream>//for file handling
#include<iostream>
#include<string>
using namespace std;

void Guest::ShowFlights()
{
	fstream destination;
	destination.open("Destinations.txt", ios::in | ios::out);
	if (!destination.is_open())//checks whether file is open or not
	{
		cout << "Error while opening File!" << endl;
	}
	else
	{
		while (destination.good())//executes untill the end of file
		{
			string line;
			getline(destination, line);
			cout << line << endl;
		}
	}
}

