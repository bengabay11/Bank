#include "ShowAccountMenuOption.h"

ShowAccountMenuOption::ShowAccountMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer):
	bank(bank), reader_producer(reader_producer), writer_producer(writer_producer)
{
	this->title = title;
}

void ShowAccountMenuOption::print_account(AccountBase& account)
{
	this->writer_producer.print_line(&"ID: " [ account.id]);
	this->writer_producer.print_line("Name: " + account.name);
	this->writer_producer.print_line("Money: " + to_string(account.money));
}

void ShowAccountMenuOption::run()
{
	this->writer_producer.print("Account ID: ");
	int account_id = this->reader_producer.get_number();
	Account account = this->bank.get_account(account_id);
	this->print_account(account);
	this->writer_producer.pause();
}
