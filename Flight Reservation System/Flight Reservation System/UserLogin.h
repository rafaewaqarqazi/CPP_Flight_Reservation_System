#pragma once
#include "Booking.h"
#include"Guest.h"
#include<fstream>
#include<string>
using namespace std;
class UserLogin : public Booking,public Guest
{
	string loginName, loginPassword;
public:
	void Login();
	void CheckUserNameandPassword(string, string, bool&);
};

