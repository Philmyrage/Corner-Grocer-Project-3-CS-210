
#include "menu.h"
#include "operations.h"
#include <iostream>
int main()
{
	Menu menu;
	Operations operations;
	menu.DisplayMenu();
	operations.PerformOperation(menu.GetMenuSelection());
	return 0;
}