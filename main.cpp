/*
	Created By: Phillip Wood
	Date: 12/12/2024
	GitHub: https://github.com/Philmyrage/Corner-Grocer-Project-3-CS-210
*/

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