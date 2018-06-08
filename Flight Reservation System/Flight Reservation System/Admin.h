#pragma once
#include"Booking.h"
#include"Guest.h"
#include"UserLogin.h"
#include<string>
using namespace std;
class Admin:public UserLogin
{
	string to, from, departure, flightNumber, seatsfile;
public:
	
	void AddDestination();
	void DeleteDestination();
	void seats(string);
	void ShowSeats();
};

