#pragma once

#include "../Abstractions//BankBase.h"
#include "../../Menu/Abstractions/MenuOptionBase.h"
#include "../../UI/Abstractions/IReaderProducer.h"
#include "../../UI/Abstractions/IWriterProducer.h"

class ShowAccountMenuOption : public MenuOptionBase
{
	private:
		BankBase& bank;
		IReaderProducer& reader_producer;
		IWriterProducer& writer_producer;
		void print_account(AccountBase& account);
	public:
		ShowAccountMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer);
		void run();
};
