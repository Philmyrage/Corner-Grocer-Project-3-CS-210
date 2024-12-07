#include "menu.h"

#include <iostream>
#include <format>

void Menu::DisplayMenu()
{
	std::cout << std::format("{:#^{}}", " MENU OPTIONS ", 100) << std::endl;
	std::cout << std::format("{:<15} {:<15} {:<15} {:<15}", 
							 " 1. Item Lookup\n", "2. Display Inventory\n", 
							 "3. Display Histogram\n", "4. Exit\n") << std::endl;
	
	
	PromptMenuSelection();
}

void Menu::PrintSelection()
{
	std::cout << menuSelection << std::endl;
}



void Menu::PromptMenuSelection()
{
	std::cout << "Select an option: ";
	try
	{
		std::cin >> menuSelection;
	}
	catch (std::iostream::failure& e)
	{
		std::cout << "Invalid input. Please try again." << std::endl;
		PromptMenuSelection();
	}
}

std::istream& operator>>(std::istream& is, EMenuSelection& selection)
{
	int value = 0;
	is >> value;
	switch (value)
	{
	case 1:
		selection = EMenuSelection::ItemLookup;
		break;
	case 2:
		selection = EMenuSelection::DisplayInventory;
		break;
	case 3:
		selection = EMenuSelection::DisplayHistogram;
		break;
	case 4:
		selection = EMenuSelection::Exit;
		break;
	default:
		is.setstate(std::ios_base::failbit);
		break;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, EMenuSelection& selection)
{
	switch (selection)
	{
	case EMenuSelection::ItemLookup:
		os << "Item Lookup";
		break;
	case EMenuSelection::DisplayInventory:
		os << "Display Inventory";
		break;
	case EMenuSelection::DisplayHistogram:
		os << "Display Histogram";
		break;
	case EMenuSelection::Exit:
		os << "Exit";
		break;
	default:
		os.setstate(std::ios_base::failbit);
		break;
	}
	return os;
}