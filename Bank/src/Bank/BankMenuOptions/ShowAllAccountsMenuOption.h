#pragma once

#include "../Abstractions//BankBase.h"
#include "../../Menu/Abstractions/MenuOptionBase.h"
#include "../../UI/Abstractions/IWriterProducer.h"

class ShowAllAccountsMenuOption: public MenuOptionBase
{
	private:
		BankBase& bank;
		IWriterProducer& writer_producer;
		void print_account(AccountBase& account);
	public:
		ShowAllAccountsMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer);
		void run();
};
