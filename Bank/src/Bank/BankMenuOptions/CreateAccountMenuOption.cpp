#include "CreateAccountMenuOption.h"

CreateAccountMenuOption::CreateAccountMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer) :
	bank(bank), writer_producer(writer_producer), reader_producer(reader_producer)
{
	this->title = title;
}

void CreateAccountMenuOption::run()
{
	this->writer_producer.print("Enter account name: ");
	string account_name = this->reader_producer.get_string();
	this->bank.create_account(account_name);
	this->writer_producer.pause();
}
