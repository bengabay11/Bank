#pragma once

#include <iostream>
#include <string>

#include "Abstractions/AccountBase.h"

using namespace std;

class Account: public AccountBase
{
	public:
		Account(string name);
		void pull_money(double money);
		void add_money(double money);
};

ostream& operator<< (ostream& out, const Account& account);