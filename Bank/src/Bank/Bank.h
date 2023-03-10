#pragma once

#include <vector>
#include <string>

#include "Account.h"
#include "Abstractions/BankBase.h"

using namespace std;

class Bank: public BankBase {
	private:
		int get_account_index(int account_id);
	public:
		Bank(string name, string city);
		void transact(int giver_account_id, int taker_account_id, double money);
		void create_account(string name);
		Account& get_account(int account_id);
		void delete_account(int account_id);
};

ostream& operator << (ostream& out, const Bank& bank);