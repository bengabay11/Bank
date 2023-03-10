#include "DeleteAccountMenuOption.h"

DeleteAccountMenuOption::DeleteAccountMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer): 
	bank(bank), reader_producer(reader_producer), writer_producer(writer_producer)
{
	this->title = title;
}

void DeleteAccountMenuOption::run()
{
	this->writer_producer.print("Account ID: ");
	int account_id = this->reader_producer.get_number();
	this->bank.delete_account(account_id);
	this->writer_producer.pause();
}
