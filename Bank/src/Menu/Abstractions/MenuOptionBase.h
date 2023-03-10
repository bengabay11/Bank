#pragma once

#include <string>

using namespace std;

class MenuOptionBase
{
	public:
		string title;
		virtual void run() = 0;
};