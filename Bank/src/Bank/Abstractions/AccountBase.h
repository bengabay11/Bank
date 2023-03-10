#pragma once

#include <string>

using namespace std;

class AccountBase
{
	public:
		int id;
		string name;
		float money;
		virtual void pull_money(double money) = 0;
		virtual void add_money(double money) = 0;
};
