#pragma once

#include "../Abstractions//BankBase.h"
#include "../../Menu/Abstractions/MenuOptionBase.h"
#include "../../UI/Abstractions/IWriterProducer.h"
#include "../../UI/Abstractions/IReaderProducer.h"

class TransactMenuOption: public MenuOptionBase
{
	private:
		BankBase& bank;
		IWriterProducer& writer_producer;
		IReaderProducer& reader_producer;
	public:
		TransactMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer);
		void run();
};
