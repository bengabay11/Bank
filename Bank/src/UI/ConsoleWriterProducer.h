#pragma once

#include <string>

#include "Abstractions/IWriterProducer.h"

using namespace std;

class ConsoleWriterProducer: public IWriterProducer
{
public:
	void clear_invalid_input(string message);
	void print(string message);
	void print_line(string message);
	void error(exception& e);
	void pause();
	void clear();
};

