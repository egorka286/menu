#ifndef _MENU_H_
#define _MENU_H_

#ifndef CLS
#ifdef __linux__
#define CLS "clear"
#else
#define CLS "cls"
#endif	// __linux__
#endif	// CLS

#include <iostream>

enum class wait { YES, NO };

class Menu
{
	struct MenuItem
	{
		char* name;
		void (*func)(void);
		enum wait w;
	};
	MenuItem* Item;
	int Count;
public:
	Menu();
	~Menu();
	void AddItem(const char*, void(*)(void) = nullptr, wait = wait::YES);
	void Run();
	//int GetSelect();
};

void wait_key(void);

#endif // _MENU_H_