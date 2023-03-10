#include <functional>

#include "Bank/Bank.h"
#include "Menu/NumericMenu.h"
#include "Menu/Abstractions/MenuOptionBase.h"
#include "UI/ConsoleReaderProducer.h"
#include "UI/ConsoleWriterProducer.h"
#include "Bank/Abstractions/BankBase.h"
#include "Bank/BankMenuOptions/CreateAccountMenuOption.h"
#include "Bank/BankMenuOptions/ShowBankMenuOption.h"
#include "Bank/BankMenuOptions/ShowAllAccountsMenuOption.h"
#include "Bank/BankMenuOptions/TransactMenuOption.h"
#include "Bank/BankMenuOptions/ShowAccountMenuOption.h"
#include "Bank/BankMenuOptions/DeleteAccountMenuOption.h"

#define MENU_TITLE "Bank Management System!"
#define BANK_NAME "Leumi"
#define BANK_CITY "Herzliya"

using namespace std;

int main()
{
    IReaderProducer* consoler_reader_producer = new ConsoleReaderProducer();
    IWriterProducer* consoler_writer_producer = new ConsoleWriterProducer();
    BankBase* bank = new Bank(BANK_NAME, BANK_CITY);
    MenuOptionBase* show_all_accounts_menu_option = new ShowBankMenuOption("Show Bank", *bank, *consoler_writer_producer);
    MenuOptionBase* show_bank_menu_option = new ShowAllAccountsMenuOption("Show All Accounts", *bank, *consoler_writer_producer);
    MenuOptionBase* create_account_menu_option = new CreateAccountMenuOption("Create Account", *bank, *consoler_writer_producer, *consoler_reader_producer);
    MenuOptionBase* transact_menu_option = new TransactMenuOption("Transact", *bank, *consoler_writer_producer, *consoler_reader_producer);
    MenuOptionBase* show_account_menu_option = new ShowAccountMenuOption("Show Account", *bank, *consoler_writer_producer, *consoler_reader_producer);
    MenuOptionBase* delete_account_menu_option = new DeleteAccountMenuOption("Delete Account", *bank, *consoler_writer_producer , *consoler_reader_producer);
    vector<MenuOptionBase*> menu_options = {
        show_bank_menu_option,
        show_all_accounts_menu_option,
        create_account_menu_option,
        transact_menu_option,
        show_account_menu_option,
        delete_account_menu_option
    };
    MenuOptionBase* menu = new NumericMenu(MENU_TITLE, menu_options, *consoler_reader_producer, *consoler_writer_producer);
    menu->run();
    delete show_all_accounts_menu_option;
    delete show_bank_menu_option;
    delete create_account_menu_option;
    delete transact_menu_option;
    delete show_account_menu_option;
    delete delete_account_menu_option;
    delete consoler_reader_producer;
    delete consoler_writer_producer;
    delete bank;
    delete menu;
    return 0;
}