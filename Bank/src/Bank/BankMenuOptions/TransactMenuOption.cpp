#include "TransactMenuOption.h"

TransactMenuOption::TransactMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer, IReaderProducer& reader_producer):
	bank(bank), writer_producer(writer_producer), reader_producer(reader_producer)
{
	this->title = title;
}

void TransactMenuOption::run()
{
	this->writer_producer.print("Enter giver account ID: ");
	int giver_account_id = this->reader_producer.get_number();
	this->writer_producer.print("Enter taker account ID: ");
	int taker_account_id = this->reader_producer.get_number();
	this->writer_producer.print("Enter amount of money: ");
	double money = this->reader_producer.get_double();
	this->bank.transact(giver_account_id, taker_account_id, money);
	this->writer_producer.pause();
}
