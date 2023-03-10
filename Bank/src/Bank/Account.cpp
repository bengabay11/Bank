#include "Account.h"

using namespace std;

Account::Account(string name) {
	srand(time(NULL));
	this->id = rand();
	this->name = name;
	this->money = 0;
}

void Account::pull_money(double money)
{
	this->money -= money;
}

void Account::add_money(double money)
{
	this->money += money;
}

ostream& operator<< (ostream& out, const Account& account) {
	out << "ID: " << account.id << endl;
	out << "Name: " << account.name << endl;
	out << "Money: " << account.money << endl;
	return out;
}
