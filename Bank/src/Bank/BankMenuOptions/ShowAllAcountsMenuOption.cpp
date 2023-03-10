#include "ShowAllAccountsMenuOption.h"

ShowAllAccountsMenuOption::ShowAllAccountsMenuOption(string title, BankBase& bank, IWriterProducer& writer_producer):
    bank(bank), writer_producer(writer_producer){
    this->title = title;
}

void ShowAllAccountsMenuOption::print_account(AccountBase& account)
{
    this->writer_producer.print_line("ID: " + account.id);
    this->writer_producer.print_line("Name: " + account.name);
    this->writer_producer.print_line("Money: " + to_string(account.money));
}

void ShowAllAccountsMenuOption::run()
{
    this->writer_producer.print_line("Accounts:");
    for (auto& account : this->bank.accounts) {
        this->print_account(account);
    }
    this->writer_producer.pause();
}
