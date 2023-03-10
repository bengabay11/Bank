#pragma once

#include <vector>

#include "../UI/Abstractions/IReaderProducer.h"
#include "../UI/Abstractions/IWriterProducer.h"
#include "Abstractions/MenuOptionBase.h"

class NumericMenu: public MenuOptionBase{
	private:
		IReaderProducer& reader_producer;
		IWriterProducer& writer_producer;
		void print_menu_options();
		MenuOptionBase* get_menu_option();
		int get_menu_option_index();
	public:
		string title;
		vector<MenuOptionBase*> menu_options;
		NumericMenu(string title, vector<MenuOptionBase*> menu_options, IReaderProducer& reader_producer, IWriterProducer& writer_producer);
		void run();
};
