/*
	Created By: Phillip Wood
	Date: 12/12/2024
	GitHub: https://github.com/Philmyrage/Corner-Grocer-Project-3-CS-210
*/
#include <memory>

#include "menu.hpp"
#include "operations.hpp"

int main()
{
	std::unique_ptr<Menu> menu = std::make_unique<Menu>();
	std::unique_ptr<Operations> operations = std::make_unique<Operations>();
	do
	{
		menu->DisplayMenu();
		operations->PerformOperation(menu->GetMenuSelection());

	}while(menu->GetMenuSelection() != EMenuSelection::Exit);

	return 0;
}