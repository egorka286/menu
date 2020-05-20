#include "menu.h"

Menu::Menu()
{
	Item = nullptr;
	Count = 0;
}

Menu::~Menu()
{
	for (int i = 0; i < Count; i++)
		delete[] Item[i].name;
	delete[] Item;
}

void Menu::AddItem(const char* name, void(*func)(void), wait w)
{
	MenuItem* old = Item;
	Item = new MenuItem[Count + 1];
	for (int i = 0; i < Count; i++)
		Item[i] = old[i];
	Item[Count].name = new char[strlen(name) + 1];
	strcpy(Item[Count].name, name);
	Item[Count].func = func;
	Item[Count].w = w;
	Count++;
	delete[] old;
}

void Menu::Run(void)
{
	int ch;
	do
	{
		system(CLS);
		for (int i = 0; i < Count; i++)
		{
			if (Item[i].name[0] == '&')
				std::cout << "0 " << (Item[i].name) + 1 << std::endl;
			else
				std::cout << i + 1 << " " << Item[i].name << std::endl;
		}
		std::cin >> ch;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			ch = -1;
		}
		else
		{
			if (ch < 1 || ch > Count)
				continue;
			if (Item[ch - 1].func)
			{
				std::cin.get();
				system(CLS);
				Item[ch - 1].func();
				if (Item[ch - 1].w == wait::YES)
					wait_key();
			}
		}
	} while (ch);
}

void wait_key(void)
{
	std::cout << " Press ENTER...";
	std::cin.get();
}