#pragma once

#include <string>
#include <vector>

#include "../Account.h"

using namespace std;

class BankBase {
public:
	string name;
	string city;
	vector<Account> accounts;
	virtual void transact(int giver_account_id, int taker_account_id, double money) = 0;
	virtual void create_account(string name) = 0;
	virtual Account& get_account(int account_id) = 0;
	virtual void delete_account(int account_id) = 0;
};