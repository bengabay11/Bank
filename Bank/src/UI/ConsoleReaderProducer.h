#pragma once

#include <string>

#include "Abstractions/IReaderProducer.h"

using namespace std;

class ConsoleReaderProducer : public IReaderProducer
{
	private:
		void validate_input(string error_message);
	public:
		string get_string();
		int get_number();
		double get_double();
};
