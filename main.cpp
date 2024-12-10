
#include "menu.hpp"
#include "operations.hpp"
#include <iostream>

int main()
{
	Menu menu;
	Operations operations;
	menu.DisplayMenu();
	operations.PerformOperation(menu.GetMenuSelection());
	return 0;
}