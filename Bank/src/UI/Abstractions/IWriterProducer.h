#pragma once

#include <string>

using namespace std;

class IWriterProducer
{
	public:
		virtual void clear_invalid_input(string message) = 0;
		virtual void print(string message) = 0;
		virtual void print_line(string message) = 0;
		virtual void error(exception& e) = 0;
		virtual void pause() = 0;
		virtual void clear() = 0;
};