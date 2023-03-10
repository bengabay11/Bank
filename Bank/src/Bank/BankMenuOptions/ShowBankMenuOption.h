#pragma once

#include "../Abstractions//BankBase.h"
#include "../../Menu/Abstractions/MenuOptionBase.h"
#include "../../UI/Abstractions/IWriterProducer.h"

class ShowBankMenuOption: public MenuOptionBase
{
	private:
		BankBase& bank;
		IWriterProducer& writer_producer;
	public:
		ShowBankMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer);
		void run();
};

