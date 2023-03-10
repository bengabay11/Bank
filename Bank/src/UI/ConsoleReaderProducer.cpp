#include <iostream>
#include <stdexcept>

#include "ConsoleReaderProducer.h"

using namespace std;
void ConsoleReaderProducer::validate_input(string error_message)
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw  invalid_argument(error_message);
    }
}

string ConsoleReaderProducer::get_string()
{
    string input;
    cin >> input;
    this->validate_input("Invalid Input");
    return input;
}

int ConsoleReaderProducer::get_number()
{
    int number;
    cin >> number;
    this->validate_input("Invalid Number");
    return number;
}

double ConsoleReaderProducer::get_double()
{
    double number;
    cin >> number;
    this->validate_input("Invalid Number");
    return number;
}
