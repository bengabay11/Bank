#pragma once

#include "../Abstractions//BankBase.h"
#include "../../Menu/Abstractions/MenuOptionBase.h"
#include "../../UI/Abstractions/IReaderProducer.h"
#include "../../UI/Abstractions/IWriterProducer.h"

class CreateAccountMenuOption : public MenuOptionBase
{
	private:
		BankBase& bank;
		IReaderProducer& reader_producer;
		IWriterProducer& writer_producer;
	public:
		CreateAccountMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer);
		void run();
};
