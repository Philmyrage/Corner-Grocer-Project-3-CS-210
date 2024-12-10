
#include "menu.hpp"
#include "operations.hpp"

int main()
{
	Menu menu;
	Operations operations;
	do
	{
		menu.DisplayMenu();
		operations.PerformOperation(menu.GetMenuSelection());

	}while(menu.GetMenuSelection() != EMenuSelection::Exit);

	return 0;
}