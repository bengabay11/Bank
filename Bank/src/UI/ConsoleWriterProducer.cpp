#include <iostream>

#include "ConsoleWriterProducer.h"

void ConsoleWriterProducer::clear_invalid_input(string message)
{
    if (!message.empty()) {
        this->print_line(message);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ConsoleWriterProducer::print(string message)
{
    cout << message;
}

void ConsoleWriterProducer::print_line(string message)
{
    cout << message << endl;
}

void ConsoleWriterProducer::error(exception& e)
{
    string exception_message = e.what();
    this->print_line("The following exception thrown: " + exception_message);
}

void ConsoleWriterProducer::pause()
{
    system("pause");
}

void ConsoleWriterProducer::clear()
{
    system("cls");
}
