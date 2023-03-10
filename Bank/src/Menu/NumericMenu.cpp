#include <stdexcept>
#include<iostream>

#include "NumericMenu.h"

using namespace std;

NumericMenu::NumericMenu(string title, vector<MenuOptionBase*> menu_options, IReaderProducer& reader_producer, IWriterProducer& writer_producer):
    title(title), menu_options(menu_options), reader_producer(reader_producer), writer_producer(writer_producer) {}

void NumericMenu::print_menu_options()
{
    this->writer_producer.clear();
    int index = 1;
    this->writer_producer.print_line(this->title);
    for (auto const& menu_option : menu_options)
    {
        cout << index << ") " << (*menu_option).title << endl;
        index++;
    }
}

int NumericMenu::get_menu_option_index()
{
    int index = -1;
    this->writer_producer.print("Enter Option (1-" + to_string(this->menu_options.size()) + "): ");
    try {
        index = this->reader_producer.get_number() - 1;
    }
    catch (invalid_argument& e)
    {
        this->writer_producer.print_line(e.what());
    }
    return index;
}

MenuOptionBase* NumericMenu::get_menu_option()
{
    int index = this->get_menu_option_index();
    while (index < 0 || index > this->menu_options.size() - 1)
    {
        this->writer_producer.print_line("Input should be a number between 1-" + to_string(this->menu_options.size()));
        index = this->get_menu_option_index();
    }
    return (this->menu_options)[index];
}

void NumericMenu::run()
{
    bool exit = false;
    while (!exit) {
        this->print_menu_options();
        (*this->get_menu_option()).run();
    }
}
