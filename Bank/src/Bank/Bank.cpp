#include "Bank.h"
#include <stdexcept>

using namespace std;

Bank::Bank(string name, string city)
{
	this->accounts = {};
	this->name = name;
	this->city = city;
}

void Bank::transact(int giver_account_id, int taker_account_id, double money) {
	this->get_account(giver_account_id).pull_money(money);
	this->get_account(taker_account_id).add_money(money);
}

void Bank::create_account(string name) {
	Account new_account(name);
	this->accounts.push_back(new_account);
}

int Bank::get_account_index(int account_id)
{
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i].id == account_id) {
			return i;
		}
	}
	throw exception("Account does not exist");
}

Account& Bank::get_account(int account_id) {
	return this->accounts[this->get_account_index(account_id)];
}

void Bank::delete_account(int account_id) {
	int deletion_index = this->get_account_index(account_id);
	this->accounts.erase(next(this->accounts.begin(), deletion_index));
}

ostream& operator<< (ostream& out, const Bank& bank) {
	out << "Name: " << bank.name << endl;
	out << "City: " << bank.city << endl;
	out << "Accounts Count: " << bank.accounts.size() << endl;
	return out;
}