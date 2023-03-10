#pragma once

#include <string>

using namespace std;

class IReaderProducer
{
	public:
		virtual string get_string() = 0;
		virtual int get_number() = 0;
		virtual double get_double() = 0;
};