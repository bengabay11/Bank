#include "ShowBankMenuOption.h"

ShowBankMenuOption::ShowBankMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer):
	bank(bank), writer_producer(writer_producer)
{
	this->title = title;
}

void ShowBankMenuOption::run()
{
	this->writer_producer.print_line("Name: " + bank.name);
	this->writer_producer.print_line("City: " + bank.city);
	this->writer_producer.print_line("Accounts Count: " + to_string(bank.accounts.size()));
	this->writer_producer.pause();
}
